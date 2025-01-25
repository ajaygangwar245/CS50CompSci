import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py filename.csv file.txt")
        sys.exit(1)

    # Read database file into a variable
    rows = []
    with open(sys.argv[1]) as dataFile:
        reader = csv.DictReader(dataFile)
        for row in reader:
            rows.append(row)

    # Read DNA sequence file into a variable
    with open(sys.argv[2]) as dnaFile:
        sequence = dnaFile.read()

    # making list subsequences from database's first row keys and excluding first index which is 'name'
    subsequences = list(rows[0].keys())[1:]

    # Find longest match of each STR in DNA sequence
    matchDict = {}
    for subsequence in subsequences:
        matchDict[subsequence] = longest_match(sequence, subsequence)

    # Check database for matching profiles
    for person in rows:
        match = 0
        for subsequence in subsequences:
            if int(person[subsequence]) == matchDict[subsequence]:
                match += 1

        # if all subsequences matched
        if match == len(subsequences):
            print(person["name"])
            return

    print("No match")
    return


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
