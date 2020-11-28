EPS = 1e-10


def ns(f):
    return next(f).strip()


def add(a, b):
    if abs(a + b) < EPS * (abs(a) + abs(b)):
        return 0.0
    return a + b


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

    def __lt__(self, other):
        if self.x == other.x:
            return self.y < other.y
        return self.x < other.x

    def __gt__(self, other):
        if self.x == other.x:
            return self.y > other.y
        return self.x > other.x


with open("../testset/beauty_contest/test1.txt", 'r') as f:
    N = int(ns(f))
    ps = [P(*map(int, ns(f).split())) for _ in range(N)]


def convex_hull(ps, n):
    ps.sort()
    qs = [None] * (n * 2)
    k = 0
    for i in range(n):
        while k > 1 and (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= 0:
            k -= 1
        qs[k] = ps[i]
        k += 1
    t = k
    for i in range(n - 2, -1, -1):
        while k > t and (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= 0:
            k -= 1
        qs[k] = ps[i]
        k += 1
    qs = qs[:k - 1]
    return qs


def dist(p1, p2):
    return (p1 - p2).dot(p1 - p2)


qs = convex_hull(ps, N)
res = 0
for i in range(len(qs)):
    for j in range(i):
        res = max(res, dist(qs[i], qs[j]))
print(res)
