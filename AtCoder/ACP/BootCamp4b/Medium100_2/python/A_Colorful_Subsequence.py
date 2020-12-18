from collections import Counter
MOD = 10**9 + 7
N = int(input())
S = Counter(input())

res = 1
for v in S.values():
    res = res * (v + 1) % MOD
print((res - 1 + MOD) % MOD)
