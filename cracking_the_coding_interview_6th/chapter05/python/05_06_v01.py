from bitint import Int, Int32


def cnt_flips(n: Int, m: Int) -> Int:
    xored = n ^ m
    res = 0
    while xored:
        res += xored & 1
        xored >>= 1
    return res


def ns(f):
    return next(f).strip()


def solve(fp: str) -> None:
    print(f"# {fp}")
    with open(fp) as f:
        n, m = map(lambda x: Int32(int(x)), ns(f).split())
    print(cnt_flips(n, m))
    print()


solve("../testcases/05_06/01.txt")
solve("../testcases/05_06/02.txt")
solve("../testcases/05_06/03.txt")
solve("../testcases/05_06/04.txt")


# # ../testcases/05_06/01.txt
# 2

# # ../testcases/05_06/02.txt
# 9

# # ../testcases/05_06/03.txt
# 5

# # ../testcases/05_06/04.txt
# 12
