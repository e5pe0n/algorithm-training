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
        return self.y < other.y if self.x == other.x else self.x < other.x

    def __gt__(self, other):
        return self.y > other.y if self.x == other.x else self.x > other.x


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
    for i in range(n - 1):
        while k > t and (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= 0:
            k -= 1
        qs[k] = ps[i]
        k += 1
    qs = qs[:k - 1]
    return qs


def dist(p1, p2):
    return (p1 - p2).dot(p1 - p2)


qs = convex_hull(ps, N)
n = len(qs)
if n == 2:
    print(dist(qs[0], qs[1]))
    exit()
i = 0
j = 0
for k in range(n):
    if qs[k] < qs[i]:
        i = k
    if qs[j] < qs[k]:
        j = k
si = i
sj = j
res = dist(qs[i], qs[j])
i += 1
while i != si or j != sj:
    res = max(res, dist(qs[i], qs[j]))
    if (qs[(i + 1) % n] - qs[i]).det(qs[(j + 1) % n] - qs[j]) < 0:
        i = (i + 1) % n
    else:
        j = (j + 1) % n
print(res)
