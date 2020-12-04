MOD = 10**9 + 7
N, K = map(int, input().split())
asc = [0] * (N + 2)
dsc = [0] * (N + 2)
for i in range(N + 1):
    asc[i + 1] = asc[i] + i
    dsc[i + 1] = dsc[i] + N - i
res = 0
for k in range(K, N + 2):
    res = (res + dsc[k] - asc[k] + 1 + MOD) % MOD
print(res)
