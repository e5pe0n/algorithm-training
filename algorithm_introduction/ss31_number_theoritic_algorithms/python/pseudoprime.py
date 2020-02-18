from collections import deque


def extend_gcd(a: int, b: int) -> int:
    if b == 0:
        return a
    return extend_gcd(b, a % b)


def modular_exponentiation(a: int, b: int, n: int) -> int:
    d = 1
    b_bits = deque()
    b_quo = b
    while b_quo != 0:
        b_bits.append(b_quo % n)
        b_quo /= 2

    while len(b_bits) > 0:
        b_i = b_bits.pop()
        d = (d * d) % n
        if b_i == 1:
            d = (d * a) % n

    return d


def pseudoprime(n: int) -> bool:
    """Return true if n is a prime.
    The case that n is determined as a prime includes error that n is not actually a prime.
    This error occured when n is a base-2 pseudoprime.

    Arguments:
        n {int} -- modulo

    Returns:
        bool -- Return true if n is a prime.
    """
    return modular_exponentiation(2, n - 1, n) == 1


def main():
    # 2 is a prime but not in Z_2
    print('pseudoprime(2):', pseudoprime(2))
    print()

    # primes
    print('pseudoprime(11):', pseudoprime(11))
    print('pseudoprime(1229):', pseudoprime(1229))
    print('pseudoprime(2801):', pseudoprime(2801))
    print()

    # composite numbers
    print('pseudoprime(1):', pseudoprime(1))
    print('pseudoprime(22):', pseudoprime(22))
    print('pseudoprime(3013):', pseudoprime(3013))
    print()

    # base-2 psuedoprimes; psuedoprime(n) returns true even n is not a prime.
    print('pseudoprime(341):', pseudoprime(341))
    print('pseudoprime(561):', pseudoprime(561))
    print('pseudoprime(645):', pseudoprime(645))
    print('pseudoprime(1105):', pseudoprime(1105))
    print()


if __name__ == '__main__':
    main()
