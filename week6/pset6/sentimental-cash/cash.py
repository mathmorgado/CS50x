from cs50 import get_float


def cash(change, coins):
    coin_count = 0

    # Avoid floating point precision by converting decimal to integer
    change *= 100

    for coin in coins:
        while True:
            if change >= coin:
                change -= coin
                coin_count += 1
            else:
                break

    return coin_count


coins = [25, 10, 5, 1]

if __name__ == "__main__":
    while True:
        change = get_float("Change owed: ")

        if change > 0:
            break

    print(cash(change, coins))
