def d2bs(n: float, bits: int) -> str:
    lst = []
    for _ in range(bits):
        n *= 2
        lst.append(str(int(n >= 1)))
        n -= int(n >= 1)
    if n != 0:
        return "ERROR"
    return ''.join(lst)


def ns(f):
    return next(f).strip()


def solve(fp: str) -> None:
    with open(fp) as f:
        n = float(ns(f))
    res = d2bs(n, 32)
    print(res)


solve("../testcases/05_02/01.txt")
solve("../testcases/05_02/02.txt")
solve("../testcases/05_02/03.txt")
