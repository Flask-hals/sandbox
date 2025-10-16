numbers = []

while True:
    try:
        I = input()
        numbers.append(int(I))
        if (len(numbers) == 2):
            low, high = 1, numbers[1]
            while (low < high):
                mid = (low + high) // 2
                if (mid ** numbers[0] < numbers[1]):
                    low = mid + 1
                else:
                    high = mid;
            print (low)
            numbers.clear()
    except EOFError:
        break