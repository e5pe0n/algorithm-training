
def validate(s):
    return "".join(c.lower() for c in s if ord('A') <= ord(c) <= ord('z'))


def is_palindrome(s):
    s = validate(s)
    b = 0
    for c in s:
        b ^= 1 << (ord(c) - ord('a'))
    return b & (b - 1) == 0


def show(f, fn, ss):
    print(f"# {fn}")
    print("\n".join([f"{s} is {'' if f(s) else 'not '}palindrome" for s in ss]))
    print()


def ns(f):
    return next(f).strip()


with open("../testcases/1_04.txt") as f:
    n = int(ns(f))
    ss = [ns(f) for _ in range(n)]

show(is_palindrome, "is_palindrome", ss)
