import sys


MAX_H = 3500


N = int(input())
for h in range(1, MAX_H + 1):
    for n in range(1, MAX_H + 1):
        p = N * h * n
        q = 4 * h * n - N * (h + n)
        if q > 0 and p % q == 0:
            w = p // q
            print(h, n, w)
            sys.exit()
