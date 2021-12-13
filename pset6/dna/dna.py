import sys
import csv

def main():
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")

    #open DNA database
    database = open(sys.argv[1], 'r')
    read_data = csv.DictReader(database)

    #open DNA sequences
    with open(sys.argv[2]) as f:
        read_dna = f.read()


    counts = {}
    for STR in read_data.fieldnames[1:]:
        counts[STR] =longest_match(read_dna, STR)

    #check each row in data for match profile
    for row in read_data:
        if all(counts[STR] ==  int(row[STR]) for STR in counts):
            print(row['name'])
            database.close()
            return
    print("No match")
    database.close()


def longest_match(read_dna, STR):
    longest = 0
    length = len(STR)
    for i in range(len(read_dna)):
        counter =0
        while True:
            start = i + length * counter
            end = start + length
            if read_dna[start:end] == STR:
                counter+= 1
            else:
                break
        longest = max(longest, counter)

    return longest

main()



