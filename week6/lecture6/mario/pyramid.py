def pyramid(height):
    for i in range(1, height + 1):
        print("#" * i)


def invert_pyramid(height):
    for i in range(1, height + 1):
        if i != height:
            print(" " * ((height - 1) - i), "#" * i)
        else:
            print("#" * i)


def double_pyramid(height):
    for i in range(1, height + 1):
        if i != height:
            print(" " * ((height - 1) - i), "#" * i, end=" ")
            print("#" * i)
        else:
            print("#" * i, end=" ")
            print("#" * i)


while True:
    try:
        height = int(input("Height: "))
        if height > 0:
            break
    except ValueError:
        print("Invalid value!\n")

pyramid(height)
print("")
invert_pyramid(height)
print("")
double_pyramid(height)
