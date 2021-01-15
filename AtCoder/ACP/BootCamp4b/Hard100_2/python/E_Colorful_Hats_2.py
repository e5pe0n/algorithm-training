MOD = 10**9 + 7
N = int(input())
A = list(map(int, input().split()))
C = [0] * (N + 1)
res = 1
n = 3
for a in A:
    if a == 0:
        res = res * n % MOD
        n -= 1
    else:
        res = res * C[a - 1] % MOD
        C[a - 1] -= 1
    C[a] += 1
print(res)
