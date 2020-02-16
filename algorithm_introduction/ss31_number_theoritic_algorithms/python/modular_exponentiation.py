from collections import deque


def modular_exponentiation(a: int, b: int, n: int) -> int:
    # c = 0
    d = 1
    b_quo = b
    b_bits = deque()
    while b_quo > 0:
        b_bits.append(b_quo % 2)
        b_quo //= 2
    while len(b_bits) > 0:
        # c *= 2
        b_i = b_bits.pop()
        d = (d * d) % n
        if b_i == 1:
            # c += 1
            d = (d * a) % n
    return d


def main():
    print("res (7, 560, 561):", modular_exponentiation(7, 560, 561))
    print("res (3, 3, 7):", modular_exponentiation(3, 3, 7))


if __name__ == '__main__':
    main()
