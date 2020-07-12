X = list(map(int, input().split()))
X.sort()
ba = X[1] - X[0]
ca = X[2] - X[0]
cb = X[2] - X[1]
if ba % 2 == 0 and ca % 2 == 0:
    print((ca + cb) // 2)
elif ba % 2 == 0:
    print(1 + (ca - 1 + cb - 1) // 2)
else:
    print((cb + ca + 1) // 2 + 1)
