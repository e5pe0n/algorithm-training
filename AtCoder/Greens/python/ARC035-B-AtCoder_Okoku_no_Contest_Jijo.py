from collections import Counter
MOD = 10**9 + 7
N = int(input())
T = [int(input()) for _ in range(N)]
C = Counter(T)
C = sorted(C.most_common())
t = 0
pen = 0
sol = 1
for k, v in C:
    s = 1
    for i in range(1, v + 1):
        pen += t + k
        t += k
        s = s * i % MOD
    sol = sol * s % MOD
print(pen)
print(sol)
