from __future__ import annotations
from typing import List


class Coord:
    def __init__(self, x: float, y: float):
        self.x: float = x
        self.y: float = y

    def __lt__(self, other: Coord):
        if self.x == other.x:
            if self.y < other.y:
                return -1
            elif self.y == other.y:
                return 0
            else:
                return 1
        if self.x < other.x:
            return -1
        else:
            return 1


class Line:
    # ax + by + c = 0
    def __init__(self, a: float, b: float, c: float):
        self.a: float = a
        self.b: float = b
        self.c: float = c


def get_line(dx1: float, dy1: float, x: float, y: float) -> Line:
    if dx1 == 0:
        return Line(1, 0, -x)
    # y = px + q
    p = dy1 / dx1
    q = y - p * x
    return Line(-p, 1, -q)


def most_passing_line(v: List[Coord]) -> Line:
    if len(v) == 1:
        return Line(1, 0, -v[0].x)
    v = sorted(v)
    max_cnt = 0
    n = len(v)
    for i in range(n - 1):
        for j in range(i + 1, n):
            dx1 = v[i].x - v[j].x
            dy1 = v[i].y - v[j].y
            cnt = 2
            for k in range(j + 1, n):
                dx2 = v[i].x - v[k].x
                dy2 = v[i].y - v[k].y
                if dx1 * dy2 == dy1 * dx2:
                    cnt += 1
            if max_cnt < cnt:
                max_cnt = cnt
                res = get_line(dx1, dy1, v[i].x, v[i].y)
    return res


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        n = int(ns(f))
        v = [Coord(*map(float, ns(f).split())) for _ in range(n)]
    res = most_passing_line(v)
    print(f"{res.a}x + {res.b}y + {res.c} = 0")
    print()


solve("../testcases/16_14/01.txt")
solve("../testcases/16_14/02.txt")
solve("../testcases/16_14/03.txt")
solve("../testcases/16_14/04.txt")
solve("../testcases/16_14/05.txt")

# # ../testcases/16_14/01.txt
# 1.0x + 1y + 4.0 = 0

# # ../testcases/16_14/02.txt
# -0.2x + 1y + -0.3999999999999999 = 0

# # ../testcases/16_14/03.txt
# -0.0x + 1y + -0.0 = 0

# # ../testcases/16_14/04.txt
# 1x + 0y + -0.0 = 0

# # ../testcases/16_14/05.txt
# 1x + 0y + -0.0 = 0
