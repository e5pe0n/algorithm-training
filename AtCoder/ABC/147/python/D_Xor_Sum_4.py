MOD = 10**9 + 7
N = int(input())
A = list(map(int, input().split()))

res = 0
b = 1
for j in range(60):
    cnt = 0
    for a in A:
        if a >> j & 1:
            cnt += 1
    res = (res + b * cnt % MOD * (N - cnt) % MOD) % MOD
    b = b * 2 % MOD
print(res)
