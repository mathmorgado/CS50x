def valid_card(credit):
    total = 0
    list_credit = [int(digit) for digit in credit]

    for n in range(len(credit) - 2, -1, -2):
        digit = int(credit[n])

        if digit * 2 <= 9:
            total += digit * 2
        else:
            total += ((digit * 2) // 10) + ((digit * 2) % 10)

        list_credit.pop(n)

    total += sum(list_credit)
    return True if total % 10 == 0 else False


def verify_card(valid):
    if valid:
        if len(credit) == 15 and credit[0:2] in ["34", "37"]:
            print("AMEX")
        elif len(credit) == 16 and int(credit[0:2]) in range(51, 56):
            print("MASTERCARD")
        elif len(credit) in [13, 16] and credit[0] == "4":
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")


if __name__ == "__main__":
    credit = input("Number: ")
    valid = valid_card(credit)

    verify_card(valid)
