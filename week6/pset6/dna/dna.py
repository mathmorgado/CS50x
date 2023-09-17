import csv
import sys


def main():
    if len(sys.argv) != 3:
        print("Usage: python dna.py FILENAME.csv FILENAME.txt")
        sys.exit(1)

    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)

        with open(sys.argv[2], "r") as seq_file:
            sequence = seq_file.read()

            if "large" in str(sys.argv[1]):
                sub_sequences = [
                    "AGATC",
                    "TTTTTTCT",
                    "AATG",
                    "TCTG",
                    "GATA",
                    "TATC",
                    "GAAA",
                    "TCTG",
                ]
            elif "small" in str(sys.argv[1]):
                sub_sequences = ["AGATC", "AATG", "TATC"]

            profile_match(reader, sequence, sub_sequences)
    return 0


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


def profile_match(reader, sequence, sub_sequences):
    found = False
    person = ""

    for profile in reader:
        for strs in sub_sequences:
            if int(profile[strs]) == longest_match(sequence, strs):
                found = True
                person = profile["name"]
            else:
                found = False
                person = ""
                break

        if found:
            print(person)
            return 0

    print("No match")
    sys.exit(2)


if __name__ == "__main__":
    main()
