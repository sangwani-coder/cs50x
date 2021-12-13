from cs50 import SQL
import sys

# cconnect to db
db = SQL("sqlite:///students.db")

#check usage
if len(sys.argv) != 2:
    print("Usage: python roster.py houseName")
    exit(1)

check_house = sys.argv[1]

result = db.execute(f"SELECT * FROM students WHERE house = '{check_house}' ORDER BY last,first")

for std in result:
  full_name = std['first'] + ' ' + (std['middle'] +' 'if std['middle'] else '') + std['last']
  print(full_name + ', '+ 'born' + ' ' + str(std['birth']))
