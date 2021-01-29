from collections import Counter
N, M = map(int, input().split())
PS = [list(input().split()) for _ in range(M)]

B = [False] * (N + 1)
C = Counter()
AC = 0
for p, s in PS:
    p = int(p)
    if not B[p]:
        if s == "AC":
            B[p] = True
            AC += 1
        else:
            C[p] += 1

WA = 0
for k, v in C.most_common():
    if B[k]:
        WA += v
print(AC, WA)
