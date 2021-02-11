INF = float('inf')
N = int(input())
A = list(map(int, input().split()))
res = -INF
for i in range(N):
    max_a = -INF
    idx_a = 0
    for j in range(N):
        if i == j:
            continue
        a = 0
        for k in range(min(i, j), max(i, j) + 1):
            if (k - min(i, j)) % 2 != 0:
                a += A[k]
        if max_a < a:
            max_a = a
            idx_a = j
    t = 0
    for j in range(min(i, idx_a), max(i, idx_a) + 1):
        if (j - min(i, idx_a)) % 2 == 0:
            t += A[j]
    res = max(res, t)
print(res)
