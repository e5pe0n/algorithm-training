N, A, B = map(int, input().split())
X = list(map(int, input().split()))
res = 0
for i in range(N - 1):
    res += min((X[i + 1] - X[i]) * A, B)
print(res)
