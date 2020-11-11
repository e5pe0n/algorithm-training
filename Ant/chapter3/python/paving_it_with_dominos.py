M = int(1e7) + 7


def ns(f):
    return next(f).strip()


with open("../testset/paving_it_with_dominos/test2.txt", 'r') as f:
    n, m, k = map(int, ns(f).split())
    color = [[False] * m for _ in range(n)]
    dp = [[0] * (1 << m) for _ in range(2)]
    for _ in range(k):
        u, v = map(int, ns(f).split())
        color[u - 1][v - 1] = True


crt = dp[0]
nxt = dp[1]
crt[0] = 1
for i in range(n - 1, -1, -1):
    for j in range(m - 1, -1, -1):
        for used in range(1 << m):
            if (used >> j & 1) or color[i][j]:
                nxt[used] = crt[used & ~(1 << j)]
            else:
                res = 0
                if j + 1 < m and not (used >> (j + 1) & 1) and not color[i][j + 1]:
                    res += crt[used | 1 << (j + 1)]
                if i + 1 < n and not color[i + 1][j]:
                    res += crt[used | 1 << j]
                nxt[used] = res % M
        crt, nxt = nxt, crt
print(crt[0])
