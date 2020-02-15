from typing import Tuple


def extend_gcd(a: int, b: int) -> Tuple[int]:
    if b == 0:
        return (a, 1, 0)
    _d, _x, _y = extend_gcd(b, a % b)
    return (_d, _y, _x - (a // b) * _y)


def res_str(res: Tuple[int]) -> str:
    d, x, y = res
    return 'd=' + str(d) + ', x=' + str(x) + ', y=' + str(y)


def main():
    print('extend_gcd(12, 13): ' + res_str(extend_gcd(12, 13)))
    print('extend_gcd(12, 6): ' + res_str(extend_gcd(12, 6)))
    print('extend_gcd(12, 18) :' + res_str(extend_gcd(12, 18)))


if __name__ == '__main__':
    main()
