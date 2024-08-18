// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    // Header buffer
    uint8_t header[HEADER_SIZE];
    // samples buffer
    int16_t buffer;

    fread(header, sizeof(uint8_t), HEADER_SIZE, input);
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, output);


    // int variable to hold the return value of fread to see if it is smaller than 1
    int endOF = 0;
    // int variable to set the end of the loop (0 is not the end and 1 is the end)
    int endOL = 0;
    // TODO: Read samples from input file and write updated data to output file
    // While not at end of loop
    while (endOL == 0)
    {
        // endOF holds return value of fread
        endOF = fread(&buffer, sizeof(int16_t), 1, input);
        // if fread returns smaller than 1, stop
        if (endOF < 1)
        {
            fclose(input);
            fclose(output);
            endOL = 1;
            return 0;
        }

        // if fread returns greater or equal to 1 then keep going
        else if (endOF >= 1)
        {
            buffer = buffer * factor;
            fwrite(&buffer, sizeof(int16_t), 1, output);
            endOF = 0;
        }
    }

    // Close files
    fclose(input);
    fclose(output);
    return 0;
}
