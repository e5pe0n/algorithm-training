import sys
N, Y = list(map(int, input().split()))
N10 = min(Y // 10000, N)
N5 = min(Y // 5000, N)
for i in range(N10 + 1):
    for j in range(N5 + 1):
        t = 10000 * i + 5000 * j + 1000 * (N - i - j)
        if t == Y and N - i - j >= 0:
            print(i, j, N - i, j)
            sys.exit()
print('-1 -1 -1')
