MOD = int(1e9) + 7
N = int(input())
A = list(map(int, input().split()))

cum = [0] * (N + 1)
for i in range(N):
    cum[i + 1] = (cum[i] + A[i]) % MOD
res = 0
for i in range(N - 1):
    res = (res + A[i] * (cum[N] - cum[i + 1])) % MOD
res = (res + MOD) % MOD
print(res)
