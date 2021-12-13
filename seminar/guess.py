from random import randrange
num = randrange(10)

for i in range(3):
    guess = int(input("guess random number: "))
    if guess == num:
       print("Congrats you guessed correctly!", guess)
    elif guess > num:
        print("Too high")
    else:
        print("too low")
print("You run out of moves")