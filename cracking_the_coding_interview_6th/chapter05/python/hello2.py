from bitint import Int, Int32


INT32_MAX = (1 << 31) - 1
INT32_MIN = -(1 << 31)


def b2d(s) -> int:
    if len(s) == 32 and s[0] == '1':
        t = int(s[1:], 2)
        return -(INT32_MAX + 1 - t)
    return int(s, 2)


def update_bits(n, m, i, j) -> int:
    if i > j or i < 0 or j >= 32:
        return 0
    all_ones = ~0
    left = all_ones << (j + 1)
    right = (1 << i) - 1
    mask = left | right
    n_cleared = n & mask
    m_shifted = m << i
    return n_cleared | m_shifted


def ns(f):
    return next(f).strip()


def solve(fp: str) -> None:
    print(f"# {fp}")
    with open(fp) as f:
        n = b2d(ns(f))
        m = b2d(ns(f))
        i, j = map(int, ns(f).split())
    res = update_bits(n, m, i, j)
    print(f"{res:032b}")
    print()


# solve("../testcases/05_01/01.txt")
solve("../testcases/05_01/02.txt")
solve("../testcases/05_01/03.txt")
solve("../testcases/05_01/04.txt")
