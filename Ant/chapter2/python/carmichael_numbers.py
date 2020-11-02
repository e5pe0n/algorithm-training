def ns(f):
    return next(f).strip()


with open("../testset/carmichael_numbers/test2.txt", 'r') as f:
    n = int(ns(f))


def mod_pow(x, n, mod):
    res = 1
    while n > 0:
        if n & 1:
            res = res * x % mod
        x = x * x % mod
        n >>= 1
    return res


for i in range(2, n):
    if mod_pow(i, n, n) != i:
        print("No")
        exit()
print("Yes")
