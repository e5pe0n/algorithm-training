MAX_B = 60
MOD = 1_000_000_007


N = int(input())
A = map(int, input().split())
C = [0] * MAX_B
for a in A:
    i = 0
    while a > 0:
        if a & 1:
            C[i] += 1
        i += 1
        a >>= 1

ans = 0
x = 1
for c in C:
    ans += c * (N - c) * x
    x *= 2
print(ans % MOD)
