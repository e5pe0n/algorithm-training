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
        return add(self.x * other.y, -self.y * other.x)


def ccw(p1, p2, q):
    d = (q - p1).det(p2 - p1)
    if d > 0:
        return 1
    elif d < 0:
        return -1
    return 0


def on_seg(p1, p2, q):
    return min(p1.x, p2.x) <= q.x <= max(p1.x, p2.x) and min(p1.y, p2.y) <= q.y <= max(p1.y, p2.y)


def intersection(p1, p2, p3, p4):
    d1 = ccw(p3, p4, p1)
    d2 = ccw(p3, p4, p2)
    d3 = ccw(p1, p2, p3)
    d4 = ccw(p1, p2, p4)
    if ((d1 > 0 and d2 < 0) or (d1 < 0 and d2 > 0)) and ((d3 > 0 and d4 < 0) or (d3 < 0 and d4 > 0)):
        return True
    return (d1 == 0 and on_seg(p3, p4, p1)) or (d2 == 0 and on_seg(p3, p4, p2)) or \
        (d3 == 0 and on_seg(p1, p2, p3)) or (d4 == 0 and on_seg(p1, p2, p4))


with open("../testset/jack_straws/test1.txt", 'r') as f:
    N, M = map(int, ns(f).split())
    p = [P(*map(int, ns(f).split())) for _ in range(N)]
    q = [P(*map(int, ns(f).split())) for _ in range(N)]
    c = [list(map(lambda x: int(x) - 1, ns(f).split())) for _ in range(M)]


g = [[intersection(p[i], q[i], p[j], q[j]) for j in range(N)] for i in range(N)]
for k in range(N):
    for i in range(N):
        for j in range(N):
            g[i][j] |= g[i][k] and g[k][j]
for a, b in c:
    if g[a][b]:
        print("CONNECTED")
    else:
        print("NOT CONNECTED")
