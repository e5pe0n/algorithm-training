def simple_gcd(a: int, b: int) -> int:
    if b == 0:
        return a
    return simple_gcd(b, a % b)


def main():
    print("simple_gcd(12, 13):", simple_gcd(12, 13))
    print("simple_gcd(12, 6):", simple_gcd(12, 6))
    print("simple_gcd(12, 18):", simple_gcd(12, 18))


if __name__ == '__main__':
    main()
