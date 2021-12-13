def main():
    row = int(input("Enter row nmber: "))
    wall(row)

def wall(x):
    for i in range(x - 2):
        for j in range(x):
            print("#", end="")
        print()

main()