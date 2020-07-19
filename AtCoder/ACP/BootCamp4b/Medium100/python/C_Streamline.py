import sys
N, M = list(map(int, input().split()))
X = list(map(int, input().split()))
if M == 1:
    print(0)
    sys.exit()
X.sort()
_X = [X[i + 1] - X[i] for i in range(M - 1)]
_X.sort()
res = sum(_X)
for i in range(min(N - 1, M - 1)):
    res -= _X[M - 2 - i]
print(res)
