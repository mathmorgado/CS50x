words = set()


def check(word):
    if word.lower() in words:
        return True
    else:
        return False


def load(dictionary):
    with open(dictionary, "r") as file:
        for line in file:
            word = line.rstrip()
            words.add(word)
    return True


def size():
    return len(words)


def unload():
    return True
