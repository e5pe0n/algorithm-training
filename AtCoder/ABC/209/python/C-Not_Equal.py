MOD = 10**9 + 7
N = int(input())
C = sorted(list(map(int, input().split())))

res = 1
for i in range(N):
    res = res * max(0, (C[i] - i)) % MOD
print(res)
