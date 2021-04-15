def extgcd(a, b, u, v):
    # solves a * u + b * v = gcd(a, b)
    d = a
    if b != 0:
        d = extgcd(b, a % b, v, u)
        v[0] -= (a // b) * u[0]
    else:
        u[0] = 1
        v[0] = 0
    return d


def pos(x, m):
    x %= m
    return (x + m) % m


def mod_inv(x, m):
    # returns the inverse of x modulo m
    # by solving x * mod_inv(x) + m * v = gcd(x, m)
    u, v = [0], [0]
    extgcd(x, m, u, v)
    u = u[0]
    return pos(u, m)


def solve(a, c, m):
    # return x satisfying a * x equiv c (mod m)
    return c * mod_inv(a, m) % m


print(solve(14, 33, 337))   # 14x equiv 33 (mod 337) -> x = 219
print(solve(64, 941, 3011))  # 64x equiv 941 (mod 3011) -> x = 2320
