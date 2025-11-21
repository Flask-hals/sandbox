def factorial(n):
    if n == 1 or n == 0:
        return 1
    n = n * factorial(n-1)
    return n

while(True):
    n = int(input())
    if (n == 0):
        break

    nFactorial = factorial(n)

    primeNumbers = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]

    primes = {}

    for i in range(len(primeNumbers)):
        primes[i+1] = 0
        while nFactorial % primeNumbers[i] == 0:
            nFactorial //= primeNumbers[i]
            primes[i+1] += 1
        if nFactorial < 2:
            break
    print(f"{n:3}! =", end="")
    for i in primes:
        if i == 16:
            print("")
            print(" "*6, end="")
        print(f"{primes[i]:3}", end="")
    print("")