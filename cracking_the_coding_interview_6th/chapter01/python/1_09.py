D = 256
Q = 10**9 + 7


def mod_pow(x, n, m):
    res = 1
    while n > 0:
        if n & 1:
            res = res * x % m
        x = x * x % m
        n >>= 1
    return res


def rabin_karp(pat, txt, d, q):
    _pat = list(map(ord, pat))
    _txt = list(map(ord, txt))
    m = len(pat)
    n = len(txt)
    h = mod_pow(d, m - 1, q)
    p, t = 0, 0
    for i in range(m):
        p = (d * p + _pat[i]) % q
        t = (d * t + _txt[i]) % q
    for i in range(n - m + 1):
        if p == t and txt[i:i + m] == pat:
            return True
        if i < n - m:
            t = (d * (t - _txt[i] * h) + _txt[i + m]) % q
            t = (t + q) % q
    return False


def is_substr(pat, string):
    return rabin_karp(pat, string, D, Q)


def is_rotation(s, t):
    return is_substr(s, t + t)


def show(f, fn, vss):
    print(f"# {fn}")
    print(
        "\n".join(list(map(
            lambda x: f"{x[0]} is {'' if f(*x) else 'not '}rotation of {x[1]}", vss))))
    print()


def ns(f):
    return next(f).strip()


with open("../testcases/1_09.txt") as f:
    n = int(ns(f))
    vss = [ns(f).split() for _ in range(n)]

show(is_rotation, "is_rotation", vss)
# is_rotation
# waterbottle is rotation of erbottlewat
# abbbbaabbba is rotation of aabbbaabbbb
# abbbaaabbba is not rotation of aabbbaabbbb
# abcdefghifkl is not rotation of abcdefabcdef
