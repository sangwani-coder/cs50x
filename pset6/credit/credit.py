from cs50 import get_string

card_number = get_string("Card number: " )
copy_card = list(card_number)

check_digit = copy_card.pop()
copy_card.reverse()

p_digits  = []

for i, d in enumerate(copy_card):
    if i % 2 ==0:
        d_digits = int(d)*2

        if d_digits > 9:
            d_digits -=9
        p_digits.append(d_digits)
    else:
        p_digits.append(int(d))

total = int(check_digit) + sum(p_digits)

if total % 10 == 0:
    if card_number[:2] == '34' or '37' and len(card_number)==15:
        print("AMEX")

    elif card_number[:2] >='51' <= '55' and len(card_number)==16:
        print("MASTERCARD")

    elif  card_number[0] == '4' and len(card_number) == 15 or len(card_number) ==16:
        print("VISA")
else:
    print("INVALID")