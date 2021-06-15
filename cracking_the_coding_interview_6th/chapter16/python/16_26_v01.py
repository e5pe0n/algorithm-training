from operator import add, sub, mul, truediv
from typing import Callable


def _eval(expr: str, head: int, last: int) -> float:
    def f(op: Callable[[float, float], float], i: int) -> float:
        return op(_eval(expr, head, i - 1), _eval(expr, i + 1, last))
    for i in range(last, head - 1, -1):
        if expr[i] == '+':
            return f(add, i)
        if expr[i] == '-':
            return f(sub, i)
    for i in range(last, head - 1, -1):
        if expr[i] == '*':
            return f(mul, i)
        if expr[i] == '/':
            return f(truediv, i)
    return int(expr[head:last + 1])


def eval(expr: str) -> float:
    return _eval(expr, 0, len(expr) - 1)


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        expr = ns(f)
    print(eval(expr))
    print()


solve("../testcases/16_26/01.txt")
solve("../testcases/16_26/02.txt")
solve("../testcases/16_26/03.txt")

# # ../testcases/16_26/01.txt
# 23.5

# # ../testcases/16_26/02.txt
# 120

# # ../testcases/16_26/03.txt
# 99.0
