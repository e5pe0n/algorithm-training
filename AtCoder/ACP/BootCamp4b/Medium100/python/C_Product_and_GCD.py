import sys
N, P = list(map(int, input().split()))
M = int(P ** (1 / N) + 1.0E-7)
for i in range(M, 0, -1):
    if P % (i ** N) == 0:
        print(i)
        sys.exit()
