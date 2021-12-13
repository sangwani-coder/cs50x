from cs50 import SQL
import csv
import sys

# Create database

db = SQL("sqlite:///students.db")

if len(sys.argv) !=2:
    print("Usage: python import.py characters.csv")
    exit(1)

with open(sys.argv[1], "r") as data:

    # Create DictReader
    reader = csv.DictReader(data)

    # Iterate over CSV file
    for row in reader:
        names = row['name'].split()
        first, middle, last = names[0], names[1] if len(names)==3 else None, names[-1]
        house = row['house']
        birth = row['birth']

    # Insert show
        db.execute("INSERT INTO students (first, middle, last,house,birth) VALUES(?, ?, ?, ?, ?)",first, middle,last,house,birth)


