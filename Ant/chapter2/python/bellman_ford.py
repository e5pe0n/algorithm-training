INF = float('inf')


def ns(f):
    return next(f).strip()


class Edge:
    def __init__(self, u, v, weight):
        self.u = u
        self.v = v
        self.weight = weight


with open("../testset/single_source_shortest_path/test1.txt", 'r') as f:
    N, K, S, T = map(int, ns(f).split())
    S -= 1
    T -= 1
    E = []
    for _ in range(K):
        u, v, weight = map(int, ns(f).split())
        u -= 1
        v -= 1
        E.append(Edge(u, v, weight))
        E.append(Edge(v, u, weight))
dist = [INF] * N
dist[S] = 0
path = [-1] * N


def relax(u, v, weight):
    global dist, path
    if dist[v] > dist[u] + weight:
        dist[v] = dist[u] + weight
        path[v] = u


def bellman_ford():
    # return True if the graph has negative loops.
    for _ in range(N - 1):
        for e in E:
            relax(e.u, e.v, e.weight)

    for e in E:
        if dist[e.v] < dist[e.u] + e.weight:
            return False
    return True


def _print_path(s, v):
    if s == v:
        print(s + 1, end='')
    elif v < 0:
        print('\nNo path', end='')
    else:
        _print_path(s, path[v])
        print(f"->{v + 1}", end='')


def print_path(s, v):
    _print_path(s, v)
    print()


bellman_ford()
print(f"shortest distance={dist[T]}")
print("shortest path=", end='')
print_path(S, T)

# shortest distance=16
# shortest path=1->3->4->6->5->7
