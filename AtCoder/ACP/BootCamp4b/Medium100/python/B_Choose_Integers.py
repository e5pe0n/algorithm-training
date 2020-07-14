A, B, C = list(map(int, input().split()))


def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


if C % gcd(A, B) == 0:
    print('YES')
else:
    print('NO')
