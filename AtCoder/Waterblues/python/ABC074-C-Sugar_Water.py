from functools import cmp_to_key
A, B, C, D, E, F = map(int, input().split())
V = []
for a in range(0, F + 1, 100 * A):
    for b in range(0, F + 1, 100 * B):
        for c in range(0, F + 1, C):
            for d in range(0, F + 1, D):
                water = a + b
                sugar = c + d
                if water + sugar <= F and water // 100 * E >= sugar:
                    V.append((water, sugar))


def cmp(p1, p2):
    if 100 * p1[1] * (p2[0] + p2[1]) < 100 * p2[1] * (p1[0] + p1[1]):
        return -1
    else:
        return 1


V.sort(key=cmp_to_key(cmp))
res = V[-1]
print(res[0] + res[1], res[1])
