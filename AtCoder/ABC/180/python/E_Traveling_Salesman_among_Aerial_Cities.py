from collections import namedtuple


INF = float('inf')


N = int(input())
C = namedtuple('C', ('x', 'y', 'z'))
Cs = [C(*map(int, input().split())) for _ in range(N)]

d = [[INF] * N for _ in range(1 << N)]
d[(1 << N) - 1][0] = 0


def distance(v, u):
    return abs(Cs[u].x - Cs[v].x) + abs(Cs[u].y - Cs[v].y) + max(0, Cs[u].z - Cs[v].z)


dist = [[distance(v, u) for u in range(N)] for v in range(N)]

for S in range((1 << N) - 2, -1, -1):
    for v in range(N):
        for u in range(N):
            d[S][v] = min(d[S][v], d[S | 1 << u][u] + dist[v][u])
print(d[0][0])
