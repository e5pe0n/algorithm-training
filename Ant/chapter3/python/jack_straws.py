EPS = 1e-10


def ns(f):
    return next(f).strip()


def add(a, b):
    if abs(a + b) < EPS * (abs(a) + abs(b)):
        return 0.0
    return float(a + b)


class P:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, other):
        return P(add(self.x, other.x), add(self.y, other.y))

    def __sub__(self, other):
        return P(add(self.x, -other.x), add(self.y, -other.y))

    def __mul__(self, d):
        return P(self.x * d, self.y * d)

    def dot(self, other):
        return add(self.x * other.x, self.y * other.y)

    def det(self, other):
        return add(self.x * other.y, - self.y * other.x)


def on_seg(p1, p2, q):
    return (p1 - q).det(p2 - q) == 0 and (p1 - q).dot(p2 - q) <= 0


def intersection(p1, p2, q1, q2):
    return p1 + (p2 - p1) * ((q2 - q1).det(q1 - p1) / (q2 - q1).det(p2 - p1))


with open("../testset/jack_straws/test1.txt", 'r') as f:
    N, M = map(int, ns(f).split())
    p = [P(*map(int, ns(f).split())) for _ in range(N)]
    q = [P(*map(int, ns(f).split())) for _ in range(N)]
    c = [list(map(lambda x: int(x) - 1, ns(f).split())) for _ in range(M)]


g = [[False] * N for _ in range(N)]
for i in range(N):
    g[i][i] = True
    for j in range(i):
        if (p[i] - q[i]).det(p[j] - q[j]) == 0:
            # parallel
            g[i][j] = g[j][i] = on_seg(p[i], q[i], p[j]) or on_seg(
                p[i], q[i], q[j]) or on_seg(p[j], q[j], p[i]) or on_seg(p[j], q[j], q[i])
        else:
            # not parallel
            r = intersection(p[i], q[i], p[j], q[j])
            g[i][j] = g[j][i] = on_seg(p[i], q[i], r) and on_seg(p[j], q[j], r)
for k in range(N):
    for i in range(N):
        for j in range(N):
            g[i][j] |= g[i][k] and g[k][j]
for a, b in c:
    if g[a][b]:
        print("CONNECTED")
    else:
        print("NOT CONNECTED")
