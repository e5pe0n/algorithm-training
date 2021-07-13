from typing import Tuple, List


def solve_equation(r1: int, r2: int) -> Tuple[int, int]:
    a = 2
    b = -2 * r1
    c = r1 * r1 - r2

    p1 = -b
    p2 = (b**2 - 4*a*c)**0.5
    p3 = 2 * a

    sol1 = int((p1 + p2) / p3)
    sol2 = r1 - sol1
    return (sol1, sol2)


def square_sum(n: int, power: int) -> int:
    return sum(i**power for i in range(1, n + 1))


def missing_two(arr: List[int]) -> Tuple[int, int]:
    max_value = len(arr) + 2
    rem_square = square_sum(max_value, 2)
    rem_one = max_value * (max_value + 1) // 2

    rem_square -= sum(map(lambda x: x*x, arr))
    rem_one -= sum(arr)

    return solve_equation(rem_one, rem_square)


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        _, _ = map(int, ns(f).split())
        arr = list(map(int, ns(f).split()))
    print(missing_two(arr))
    print()


solve("../testcases/17_19/01.txt")
solve("../testcases/17_19/02.txt")

# # ../testcases/17_19/01.txt
# (9, 3)

# # ../testcases/17_19/02.txt
# (16, 13)
