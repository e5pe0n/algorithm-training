from collections import Counter
N, M = map(int, input().split())
PY = [list(map(int, input().split())) + [i] for i in range(M)]
PY.sort(key=lambda x: x[1])
C = Counter()
res = []
for p, y, idx in PY:
    p = str(p)
    if len(p) < 6:
        p = f"{int(p):06d}"
    C[p] += 1
    c = str(C[p])
    if len(c) < 6:
        c = f"{int(c):06d}"
    res.append((idx, p + c))
res.sort()
print('\n'.join(list(map(lambda x: x[1], res))))
