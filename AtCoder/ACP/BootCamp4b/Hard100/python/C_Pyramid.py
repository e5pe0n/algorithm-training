import sys


class Coord:
    def __init__(self, x, y, h):
        self.x = x
        self.y = y
        self.h = h


N = int(input())
C = [Coord(*(map(int, input().split()))) for _ in range(N)]
max_h = max(map(lambda x: x.h, C))

for cx in range(101):
    for cy in range(101):
        for h in range(max_h, max_h + 201):
            determined = True
            for c in C:
                if max(h - abs(c.x - cx) - abs(c.y - cy), 0) != c.h:
                    determined = False
            if determined:
                print(cx, cy, h)
                sys.exit()
