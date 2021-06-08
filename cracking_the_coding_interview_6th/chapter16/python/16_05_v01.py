def cnt_trailing_zeros(n: int):
    res = 0
    while n > 0:
        res += n // 5
        n //= 5
    return res


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        n = int(ns(f))
    print(f"{n}: {cnt_trailing_zeros(n)}\n")


solve("../testcases/16_05/01.txt")
solve("../testcases/16_05/02.txt")
solve("../testcases/16_05/03.txt")
solve("../testcases/16_05/04.txt")
solve("../testcases/16_05/05.txt")


# # ../testcases/16_05/01.txt
# 10: 2

# # ../testcases/16_05/02.txt
# 50: 12

# # ../testcases/16_05/03.txt
# 100: 24

# # ../testcases/16_05/04.txt
# 500: 124

# # ../testcases/16_05/05.txt
# 50000: 12499
