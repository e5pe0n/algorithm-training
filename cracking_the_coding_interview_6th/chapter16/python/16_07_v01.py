def ma(n: int, m: int) -> int:
    c = n + m
    d = abs(n - m)
    return (c + d) // 2


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        n, m = map(int, ns(f).split())
    print(ma(n, m))
    print()


solve("../testcases/16_07/01.txt")
solve("../testcases/16_07/02.txt")
solve("../testcases/16_07/03.txt")
solve("../testcases/16_07/04.txt")
solve("../testcases/16_07/05.txt")
solve("../testcases/16_07/06.txt")
solve("../testcases/16_07/07.txt")


# # ../testcases/16_07/01.txt
# 2

# # ../testcases/16_07/02.txt
# 3

# # ../testcases/16_07/03.txt
# 1

# # ../testcases/16_07/04.txt
# 1

# # ../testcases/16_07/05.txt
# 2

# # ../testcases/16_07/06.txt
# -3

# # ../testcases/16_07/07.txt
# -2
