#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

// detect start of jpg file function
int detectHeader(uint8_t buffer[]);

int main(int argc, char *argv[])
{
    // Create the buffer variable (512 byte chunks)
    uint8_t buffer[512];
    // Create a file counter variable
    int fileCount = 0;

    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE (like: ./recover IMAGE)\n");
        return 1;
    }

    // Open memory card file
    FILE *rawFile = fopen(argv[1], "r");
    if (rawFile == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    // int var to hold return result of detectHeader function
    // inicially set to NOT be a header (any number that isn't 0)
    int isHeader = 9;
    // Pointer to dynamic jpg file name
    char *ptJpgName = malloc(8 * sizeof(char));
    // Pointer to newly created recovered files
    FILE *ptRecoveredJpg = NULL;

    // while reading memory card to buffer in 512 byte chunks, do:
    while (fread(buffer, 1, 512, rawFile) == 512)
    {
        // detect the header (will return 0 if header is found and 1 if not)
        isHeader = detectHeader(buffer);
        // If you find a header you will ALWAYS write to a file
        if (isHeader == 0)
        {
            // If it's NOT the first jpg found
            if (fileCount > 0)
            {
                // CLOSE THE LAST JPG FILE
                fclose(ptRecoveredJpg);
            }
            // AFTER CODE BELOW THE FILE NAME WILL BE STORED IN PTJPGNAME
            sprintf(ptJpgName, "%03i.jpg", fileCount);
            // create a jpg file with dynamic name
            ptRecoveredJpg = fopen(ptJpgName, "w");
            // if this is the first jpg
            if (ptRecoveredJpg != NULL)
            {
                // increment file counter
                fileCount++;
            }
        }
        // IF ALREADY FOUND A FIRST JPEG KEEP WRITING THE BLOCKS TO CURRENT JPEG
        if (fileCount > 0)
        {
            fwrite(buffer, sizeof(char), 512, ptRecoveredJpg);
        }
    }
    // Close memory card pointer
    fclose(rawFile);
    // Close recovered jpg pointer
    fclose(ptRecoveredJpg);
    // Free dynamically allocated memory
    free(ptJpgName);
    // Exit
    return 0;
}

// RETURN 0 if header is found and 1 if NOT found
int detectHeader(uint8_t buffer[])
{
    // Check to see if the first 4 bytes in the 512 bytes chunk matches jpg requirements
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        // If you found a header
        return 0;
    }
    else
    {
        // If you didn't find a header
        return 1;
    }
}