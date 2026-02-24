numbers = []

while True:
    try:
        I = input()
        if I.strip() == "":
            continue
        numbers.append(int(I))
        if (len(numbers) == 3):
            print (pow(numbers[0], numbers[1], numbers[2]))
            numbers.clear()
    except EOFError:
        break