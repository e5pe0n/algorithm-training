from collections import namedtuple


INF = float('inf')


N = int(input())
C = namedtuple('C', ('x', 'y', 'z'))
Cs = [C(*map(int, input().split())) for _ in range(N)]


def distance(u, v):
    return abs(Cs[v].x - Cs[u].x) + abs(Cs[v].y - Cs[u].y) + max(0, Cs[v].z - Cs[u].z)


dist = [[distance(u, v) for v in range(N)] for u in range(N)]
d = [[INF] * N for _ in range(1 << N)]
d[0][0] = 0

for S in range(1, 1 << N):
    for u in range(N):
        for v in range(N):
            d[S][v] = min(d[S][v], d[S & ~(1 << v)][u] + dist[u][v])
print(d[-1][0])
