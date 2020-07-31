INF = 1_000_000_007


def comb(n, k):
    if n == 0 or k == 0:
        return 1
    a = n
    for i in range(n - 1, n - k, -1):
        a *= i
    b = 1
    for i in range(2, k + 1):
        b *= i
    return a // b


t = 8
_t = 0
_b = (t - 1) // 2
_a = (t + 1) // 2
for i in range(t // 2 + 1):
    _t += comb(t - i, i)
print(_t % INF)
