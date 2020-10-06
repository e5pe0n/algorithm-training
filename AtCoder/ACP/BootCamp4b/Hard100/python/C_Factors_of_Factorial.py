import math


MOD = 1_000_000_007


N = int(input())
C = [0] * (N + 1)
for i in range(2, N + 1):
    n = i
    for j in range(2, int(math.sqrt(n)) + 2):
        if n % j != 0:
            continue
        while n % j == 0:
            C[j] += 1
            n //= j
    if n > 1:
        C[n] += 1
ans = 1
for c in C:
    if c > 0:
        ans *= (c + 1)
print(ans % MOD)
