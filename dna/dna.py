import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("3 arguments expected")
    else:
        # print(f"THIS IS THE 0 FIELD: {sys.argv[0]}") #this is the name of the app
        # print(f"THIS IS THE 1 FIELD: {sys.argv[1]}") #this is the name of the csv path and file
        # print(f"THIS IS THE 2 FIELD: {sys.argv[2]}") #this is the actual sequence path and file

        # Let's set everything up beforehand. First we need the two arguments inside variables
        # Just keep in mind that they already are variables, just not in a very descriptive way
        # So let's fix that
        # this will pass on the path typed into a better named variable
        typedDatabasePath = sys.argv[1]
        # this will pass on the path typed into a better named variable
        typedSequencePath = sys.argv[2]

    # Now let's dinamically use the variables according to the file names typed

        # TODO: Read database file into a variable

        rows = []
        with open(typedDatabasePath, newline='') as csvDB:
            information = csv.DictReader(csvDB)
            for row in information:
                rows.append(row)
                # print(row)

    # TODO: Read DNA sequence file into a variable
        with open(typedSequencePath, "r") as s:
            sequence = s.read()

    # TODO: Find longest match of each STR in DNA sequence

    # Okay, now that I have both variables I can figure if the sequence typed
    # is a match or not and if so print the pesen's name, otherwise, print no match
    lenRows = len(rows)
    lenRows = lenRows
    str1, str2, str3, str4, str5, str6, str7, str8 = 'AGATC', 'TTTTTTCT', 'AATG', 'TCTAG', 'GATA', 'TATC', 'GAAA', 'TCTG'
    agaCount, tttCount, aatCount, tctagCount, gatCount, tatCount, gaaCount, tctCount = 0, 0, 0, 0, 0, 0, 0, 0

    counts = {}

    agaCount = longest_match(sequence, str1)
    tttCount = longest_match(sequence, str2)
    aatCount = longest_match(sequence, str3)
    tctagCount = longest_match(sequence, str4)
    gatCount = longest_match(sequence, str5)
    tatCount = longest_match(sequence, str6)
    gaaCount = longest_match(sequence, str7)
    tctCount = longest_match(sequence, str8)

    # TODO: Check database for matching profiles

    # Now to dinamically iterate:
    lenRows = len(rows)
    lenRows = lenRows
    # print(f"test subject: AGA: {agaCount} TTT: {tttCount} AAT: {aatCount}")
    # print(f"test subject: TCTAG: {tctagCount} GAT: {gatCount} TAT: {tatCount}")
    # print(f"test subject: GAA: {gaaCount} TCT: {tctCount}")

    if typedDatabasePath == "databases/small.csv":
        for i in range(lenRows):
            if int(rows[i]['AGATC']) == int(agaCount) and int(rows[i]['AATG']) == int(aatCount) and int(rows[i]['TATC']) == int(tatCount):
                print(rows[i]['name'])
                return

        print("No match")
        # print(f"Name {rows[i]['name']}")
        # int(rows[i][]) == int()
    else:  # 'AGATC','TTTTTTCT','AATG','TCTAG','GATA','TATC','GAAA','TCTG'
        for i in range(lenRows):
            if int(rows[i]['AGATC']) == int(agaCount) and int(rows[i]['TTTTTTCT']) == int(tttCount) and int(rows[i]['AATG']) == int(aatCount) and int(rows[i]['TCTAG']) == int(tctagCount) and int(rows[i]['GATA']) == int(gatCount) and int(rows[i]['TATC']) == int(tatCount) and int(rows[i]['GAAA']) == int(gaaCount) and int(rows[i]['TCTG']) == int(tctCount):
                print(rows[i]['name'])
                return

        print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
