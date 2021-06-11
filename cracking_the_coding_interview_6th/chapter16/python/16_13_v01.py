from __future__ import annotations


class Coord:
    def __init__(self, x: float, y: float):
        self.x: float = x
        self.y: float = y

    def __add__(self, other: Coord) -> Coord:
        return Coord(self.x + other.x, self.y + other.y)

    def __sub__(self, other: Coord) -> Coord:
        return Coord(self.x - other.x, self.y - other.y)

    def __mul__(self, d: float) -> Coord:
        return Coord(self.x * d, self.y * d)

    def __truediv__(self, d: float) -> Coord:
        return Coord(self.x / d, self.y / d)


class Line:
    # ax + by + c = 0
    def __init__(self, a: float, b: float, c: float):
        self.a: float = a
        self.b: float = b
        self.c: float = c


def half_line(topleft1: Coord, btmright1: Coord, topleft2: Coord, btmright2: Coord) -> Line:
    center1 = (topleft1 + btmright1) / 2
    center2 = (topleft2 + btmright2) / 2
    dx = center1.x - center2.x
    dy = center1.y - center2.y
    if dx == 0:
        return Line(1, 0, -center1.x)
    # y = px + q
    p = dy / dx
    q = center1.y - p * center1.x
    return Line(-p, 1, -q)


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        x0, y0, x1, y1 = map(int, ns(f).split())
        topleft1, btmright1 = Coord(x0, y0), Coord(x1, y1)
        x0, y0, x1, y1 = map(int, ns(f).split())
        topleft2, btmright2 = Coord(x0, y0), Coord(x1, y1)
    line = half_line(topleft1, btmright1, topleft2, btmright2)
    print(f"{line.a}x + {line.b}y + {line.c} = 0")
    print()


solve("../testcases/16_12/01.txt")
solve("../testcases/16_12/02.txt")
solve("../testcases/16_12/03.txt")
solve("../testcases/16_12/04.txt")
solve("../testcases/16_12/05.txt")
solve("../testcases/16_12/06.txt")

# # ../testcases/16_12/01.txt
# -0.5x + 1y + -4.5 = 0

# # ../testcases/16_12/02.txt
# -1.4x + 1y + 14.399999999999999 = 0

# # ../testcases/16_12/03.txt
# 1.75x + 1y + 11.25 = 0

# # ../testcases/16_12/04.txt
# 0.0x + 1y + -1.0 = 0

# # ../testcases/16_12/05.txt
# 1x + 0y + -1.0 = 0

# # ../testcases/16_12/06.txt
# 1x + 0y + -0.0 = 0
