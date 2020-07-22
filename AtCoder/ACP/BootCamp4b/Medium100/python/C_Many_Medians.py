N = int(input())
X = list(map(int, input().split()))
_X = sorted(X)
m = N // 2
for x in X:
    if x >= _X[m]:
        print(_X[m - 1])
    else:
        print(_X[m])
