while True:
    try:
        height = int(input("Height: "))
        if height > 0:
            break
    except ValueError:
        print("\nError: Not an intenger\n")

for h in range(height):
    print("#")
