INF = 1_000_000_007
N = int(input())
S = input()
C = [0] * 26
for s in S:
    C[ord(s) - ord('a')] += 1
res = 1
for c in C:
    if c > 0:
        res *= (c + 1) % INF
print(res - 1)
