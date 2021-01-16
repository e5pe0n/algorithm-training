MOD = 10**9 + 7
N = int(input())
A = list(map(int, input().split()))

res = 0
b = 1
for j in range(60):
    one = 0
    for a in A:
        if a >> j & 1:
            one += 1
    _one = one * (N - one) % MOD
    res = (res + b * _one % MOD) % MOD
    b = b * 2 % MOD
print(res)
