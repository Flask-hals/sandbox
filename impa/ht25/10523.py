while True:
    try:
        NA = input()
        NA = NA.split()
        N = int(NA[0])
        A = int(NA[1])
        sum = 0;
        for i in range(1, N+1):
            sum += i*pow(A,i)
        print(sum)
    except EOFError:
        break