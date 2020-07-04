import sys
N, Y = [int(i) for i in input().split()]
for i in range(N + 1):
    for j in range(N + 1 - i):
        if 10000 * i + 5000 * j + 1000 * (N - i - j) == Y:
            print(i, j, N - i - j)
            sys.exit()
print('-1 -1 -1')
