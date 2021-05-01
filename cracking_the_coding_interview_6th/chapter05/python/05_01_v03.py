from bitint import Int, Int32


def ns(f):
    return next(f).strip()


def update_bits(n: Int, m: Int, i: int, j: int) -> Int:
    if i > j or i < 0 or j >= 32:
        return 0
    all_ones = ~Int32(0)
    left = all_ones << (j + 1)
    right = (1 << i) - 1
    mask = left | right
    n_cleared = n & mask
    m_shifted = m << i
    return n_cleared | m_shifted


def solve(fp: str) -> None:
    print(f"# {fp}")
    with open(fp) as f:
        n = Int32(ns(f))
        m = Int32(ns(f))
        i, j = map(int, ns(f).split())
    res = update_bits(n, m, i, j)
    print(f"{res:032b}")
    print()


solve("../testcases/05_01/01.txt")
solve("../testcases/05_01/02.txt")
solve("../testcases/05_01/03.txt")
solve("../testcases/05_01/04.txt")

# # ../testcases/05_01/01.txt
# 00000000000000000000010001001100

# # ../testcases/05_01/02.txt
# 11001000101111001001010111010001

# # ../testcases/05_01/03.txt
# 11001000101110101011001001010111

# # ../testcases/05_01/04.txt
# 10010010101110101011010011010001
