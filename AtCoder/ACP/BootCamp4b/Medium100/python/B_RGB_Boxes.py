X = list(map(int, input().split()))
N = X[-1]
X = X[:3]
X.sort()
N2 = N // X[2]
N1 = N // X[1]
cnt = 0
for i in range(N2 + 1):
    for j in range(N1 + 1):
        if X[2] * i + X[1] * j + X[0] * max(0, (N - X[2] * i - X[1] * j) // X[0]) == N:
            cnt += 1
print(cnt)
