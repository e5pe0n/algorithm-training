INF = float('inf')


def ns(f):
    return next(f).strip()


with open("../testset/all_pairs_shortest_path/test1.txt", 'r') as f:
    N, K = map(int, ns(f).split())
    d = [[0 if i == j else INF for j in range(N)] for i in range(N)]
    for _ in range(K):
        u, v, weight = map(int, ns(f).split())
        u -= 1
        v -= 1
        d[u][v] = weight
        # if non-direction graph add d[v][u]
        # d[v][u] = weight


def warshall_floyd():
    global d
    for k in range(N):
        for i in range(N):
            for j in range(N):
                d[i][j] = min(d[i][j], d[i][k] + d[k][j])


warshall_floyd()
for _d in d:
    print(' '.join(map(str, _d)))

# 0 1 -3 2 -4
# 3 0 -4 1 -1
# 7 4 0 5 3
# 2 -1 -5 0 -2
# 8 5 1 6 0
