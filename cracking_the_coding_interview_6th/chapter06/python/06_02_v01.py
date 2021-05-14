from bitint import Int64, Int


def dfs(i: int, bit: Int, n: int, m: int) -> bool:
    if i == n * m:
        return bit == Int64(-1)
    if bit & (Int64(1) << i):
        return dfs(i + 1, bit, n, m)
    res = False
    if i % m != m - 1 and (~bit & (Int64(1) << (i + 1))):
        res |= dfs(i + 1, bit | (Int64(1) << i) | (Int64(1) << (i + 1)), n, m)
    if i + m < n * m and (~bit & (Int64(1) << (i + m))):
        res |= dfs(i + 1, bit | (Int64(1) << i) | (Int64(1) << (i + m)), n, m)
    return res


def ns(f):
    return next(f).strip()


def solve(fp: str) -> None:
    print(f"# {fp}")
    with open(fp) as f:
        n, m = map(int, ns(f).split())
        bit = Int64(0)
        for i in range(n):
            line = ns(f)
            for j, c in enumerate(line):
                if c == 'x':
                    bit |= Int64(1) << (m * i + j)
    print("possible" if dfs(0, bit, n, m) else "impossible")
    print()


# Python is too late to solve 8x8 problems
# solve("../testcases/06_02/01.txt")
# solve("../testcases/06_02/02.txt")
# solve("../testcases/06_02/03.txt")
