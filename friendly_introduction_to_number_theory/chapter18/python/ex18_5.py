P = 187963
Q = 163841
M = P * Q
K = 48611


def mod_pow(x, n, m):
    res = 1
    while n > 0:
        if n & 1:
            res = res * x % m
        x = x * x % m
        print(res, x)
        n >>= 1
    return res


print(mod_pow(101, K, M))
