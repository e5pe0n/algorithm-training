N = int(input())
T, X, Y = [0], [0], [0]
for _ in range(N):
    t, x, y = map(int, input().split())
    T.append(t)
    X.append(x)
    Y.append(y)

for i in range(N):
    dt = T[i + 1] - T[i]
    dd = abs(X[i + 1] - X[i]) + abs(Y[i + 1] - Y[i])
    if dt < dd or dt % 2 != dd % 2:
        print("No")
        exit()
print("Yes")
