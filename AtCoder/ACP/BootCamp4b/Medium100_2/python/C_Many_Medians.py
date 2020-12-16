from copy import deepcopy
N = int(input())
X = list(map(int, input().split()))
_X = sorted(deepcopy(X))
md1 = (N - 1) // 2
md2 = md1 + 1
for i in range(N):
    if X[i] <= _X[md1]:
        res = _X[md2]
    else:
        res = _X[md1]
    print(res)
