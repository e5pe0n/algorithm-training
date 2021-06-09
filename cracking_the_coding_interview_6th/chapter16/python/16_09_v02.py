def neg(a: int) -> int:
    negated = 0
    new_sign = 1 if a < 0 else -1
    while a != 0:
        negated += new_sign
        a += new_sign
    return negated


def _sub(a: int, b: int) -> int:
    return a + neg(b)


def _mul(a: int, b: int) -> int:
    if abs(a) < abs(b):
        return _mul(b, a)
    res = 0
    for i in range(0, abs(b)):
        res += a
    return res if b >= 0 else neg(res)


def _div(a: int, b: int) -> int:
    if b == 0:
        raise ZeroDivisionError("zero division")
    abs_a = abs(a)
    abs_b = abs(b)
    res = 0
    product = 0
    while product + abs_b <= abs_a:
        product += abs_b
        res += 1
    return res if (a < 0 and b < 0) or (a > 0 and b > 0) else neg(res)


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        a, b = map(int, ns(f).split())
    print(f"{a} - {b} = {_sub(a, b)}")
    print(f"{a} * {b} = {_mul(a, b)}")
    try:
        print(f"{a} / {b} = {_div(a, b)}")
    except ZeroDivisionError as e:
        print(e)
    print()


solve("../testcases/16_09/01.txt")
solve("../testcases/16_09/02.txt")
solve("../testcases/16_09/03.txt")
solve("../testcases/16_09/04.txt")
solve("../testcases/16_09/05.txt")
solve("../testcases/16_09/06.txt")
solve("../testcases/16_09/07.txt")
solve("../testcases/16_09/08.txt")
# solve("../testcases/16_09/09.txt")


# # ../testcases/16_09/01.txt
# 20 - 5 = 15
# 20 * 5 = 100
# 20 / 5 = 4

# # ../testcases/16_09/02.txt
# 1 - 1 = 0
# 1 * 1 = 1
# 1 / 1 = 1

# # ../testcases/16_09/03.txt
# 1 - 0 = 1
# 1 * 0 = 0
# zero division

# # ../testcases/16_09/04.txt
# 0 - 1 = -1
# 0 * 1 = 0
# 0 / 1 = 0

# # ../testcases/16_09/05.txt
# -48 - 16 = -64
# -48 * 16 = -768
# -48 / 16 = -3

# # ../testcases/16_09/06.txt
# -48 - -16 = -32
# -48 * -16 = 768
# -48 / -16 = 3

# # ../testcases/16_09/07.txt
# -9 - 2 = -11
# -9 * 2 = -18
# -9 / 2 = -4

# # ../testcases/16_09/08.txt
# 9 - 2 = 7
# 9 * 2 = 18
# 9 / 2 = 4
