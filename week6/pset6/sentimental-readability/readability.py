def calc_grade(text):
    letters = 0
    words = 1
    sentences = 0

    for c in text:
        if c.isalpha():
            letters += 1
        elif c == " ":
            words += 1
        elif c in [".", "!", "?"]:
            sentences += 1

    L = letters / words * 100
    S = sentences / words * 100

    index = 0.0588 * L - 0.296 * S - 15.8
    return round(index)


if __name__ == "__main__":
    text = input("Text: ")

    grade = calc_grade(text)

    if grade < 1:
        print("Before Grade 1")
    elif grade >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")
