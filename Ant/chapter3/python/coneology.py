from bisect import bisect_left


def ns(f):
    return next(f).strip()


class Circle:
    def __init__(self, x, y, r):
        self.x = x
        self.y = y
        self.r = r


with open("../testset/coneology/test1.txt", 'r') as f:
    N = int(ns(f))
    C = [Circle(*map(int, ns(f).split())) for _ in range(N)]


events = []
for i in range(N):
    events.append((C[i].x - C[i].r, i))
    events.append((C[i].x + C[i].r, N + i))


events.sort()
outers = []
res = []
for i in range(len(events)):
    idx = events[i][2] % N
    it = bisect_left(outers, (C[idx].y, idx))
