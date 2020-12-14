N, T = map(int, input().split())
t = list(map(int, input().split()))

res = 0
for i in range(N - 1):
    res += min(T, t[i + 1] - t[i])
res += T
print(res)
