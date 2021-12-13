from cs50 import get_float

coins = [25,10,5,1]

while True:
    change = get_float("Change owed: ")
    if change > 0:
        break
cents = round(change*100)

#change is valid
total = 0
for coin in coins:
    total += cents // coin
    cents %= coin
print(total)



