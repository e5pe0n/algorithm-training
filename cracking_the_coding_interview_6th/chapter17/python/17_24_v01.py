from typing import List, Tuple


class Res:
    def __init__(
        self,
        sm: int = -float('inf'),
        topleft: Tuple[int, int] = (-1, -1),
        btmright: Tuple[int, int] = (-1, -1)
    ):
        self.sm = sm
        self.topleft = topleft
        self.btmright = btmright

    def __repr__(self):
        return f"{self.sm}, ({self.topleft}, {self.btmright})"


def find_max_submat(mat: List[List[int]]) -> Res:
    n = len(mat)
    m = len(mat[0])
    sums = [[0] * (m + 1) for _ in range(n)]
    for i in range(n):
        for j in range(m):
            sums[i][j + 1] = sums[i][j] + mat[i][j]
    res = Res()
    for left in range(m):
        for right in range(left, m):
            t = 0
            _i = 0
            for i in range(n):
                t += sums[i][right + 1] - sums[i][left]
                if t > res.sm:
                    res.sm = t
                    res.topleft = (_i, left)
                    res.btmright = (i, right)
                if t < 0:
                    _i = i + 1
                    t = 0
    return res


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        n, _ = map(int, ns(f).split())
        mat = [list(map(int, ns(f).split())) for _ in range(n)]
    print(find_max_submat(mat))
    print()


solve("../testcases/17_24/01.txt")
solve("../testcases/17_24/02.txt")
solve("../testcases/17_24/03.txt")
solve("../testcases/17_24/04.txt")
solve("../testcases/17_24/05.txt")
solve("../testcases/17_24/06.txt")


# # ../testcases/17_24/01.txt
# 16, ((3, 0), (3, 1))

# # ../testcases/17_24/02.txt
# 30, ((1, 1), (4, 3))

# # ../testcases/17_24/03.txt
# 33, ((7, 0), (9, 4))

# # ../testcases/17_24/04.txt
# -1, ((5, 0), (5, 0))

# # ../testcases/17_24/05.txt
# 38, ((8, 0), (9, 4))

# # ../testcases/17_24/06.txt
# 111, ((0, 0), (4, 4))
