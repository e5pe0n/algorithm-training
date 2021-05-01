MAX = 2**31


def ns(f):
    return next(f).strip()


def b2d(s: str) -> int:
    if len(s) == 32 and s[0] == '1':
        t = int(s[1:], 2)
        return -(MAX - t)
    return int(s, 2)


def update_bits(n: int, m: int, i: int, j: int) -> int:
    if i > j or i < 0 or j >= 32:
        return 0
    all_ones = 2**32 - 1
    print(f"all_ones={all_ones:32b}")
    left = all_ones << (j + 1)
    right = (1 << i) - 1
    mask = left | right
    print(f"left={left:032b}")
    print(f"right={right:032b}")
    print(f"mask={mask:032b}")
    print(f"n={n:032b}")
    n_cleared = n & mask
    print(f"n_cleared={n_cleared:032b}")
    m_shifted = m << i
    return n_cleared | m_shifted


def solve(fp: str) -> None:
    print(f"# {fp}")
    with open(fp) as f:
        n = b2d(ns(f))
        m = b2d(ns(f))
        i, j = map(int, ns(f).split())
    print(n)
    res = update_bits(n, m, i, j)
    print(f"{res:032b}")
    print()


# solve("../testcases/05_01/01.txt")
solve("../testcases/05_01/02.txt")
# solve("../testcases/05_01/03.txt")
# solve("../testcases/05_01/04.txt")
print(MAX)

11001000101110101011001001010111
