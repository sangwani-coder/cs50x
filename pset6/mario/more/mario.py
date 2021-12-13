from cs50  import get_int

while True:
    height = get_int("Enter height: ")

    if height in range(1,9):
        try:
            for row in range (1, height +1):
                print(" " * (height - row) + "#" * row + " " * 2 + "#" * row)

            break
        except ValueError:
            print("Input must be between 1 and 8")









