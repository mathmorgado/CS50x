def invert_pyramid(height):
    for i in range(1, height + 1):
        if i != height:
            print(" " * ((height - 1) - i), "#" * i)
        else:
            print("#" * i)


while True:
    try:
        height = int(input("Height: "))
        if height > 0 and height < 9:
            break
    except ValueError:
        print("Invalid value!\n")

invert_pyramid(height)
