from typing import Tuple


def extend_gcd(a: int, b: int) -> Tuple[int]:
    if b == 0:
        return (a, 1, 0)
    d, _x, _y = extend_gcd(b, a % b)
    return (d, _y, _x - (a // b) * _y)


def add_offset(x: int, n: int) -> int:
    return (x + n) % n


def modular_linear_equation_solver(a: int, b: int, n: int) -> Tuple[int]:
    d, _x, _y = extend_gcd(a, n)
    if b % d == 0:
        x0 = _x * (b // d)
        return tuple(add_offset(x0 + i * (n // d), n) for i in range(d))
    return ()


def main():
    print(modular_linear_equation_solver(14, 30, 100))


if __name__ == '__main__':
    main()
