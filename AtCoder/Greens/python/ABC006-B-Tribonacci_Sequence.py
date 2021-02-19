MOD = 10_007
N = int(input())
d = [0] * max(3 + 1, N + 1)
d[3] = 1
for i in range(4, N + 1):
    d[i] = ((d[i - 1] + d[i - 2]) % MOD + d[i - 3]) % MOD
print(d[N])
