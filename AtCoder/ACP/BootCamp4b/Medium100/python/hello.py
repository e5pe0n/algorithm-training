INF = 1_000_000_007

t = 20
_t = 2
_b = (t - 1) // 2
_a = t // 2 + 1
b = 1
for i in range(1, _b + 1):
    b *= i
a = b
for i in range(_b + 1, _a + 1):
    a *= i
_c = _a - _b
c = 1
for i in range(1, _a - _b + 1):
    c *= i
for _ in range(_b):
    print(f'_a={_a}, _b={_b}, _c={_c}')
    print(f'a={a}, b={b}, c={c}')
    _t += a // b // c
    _a += 1
    a *= _a
    b //= _b
    _b -= 1
    _c += 1
    c *= _c
    _c += 1
    c *= _c
print(_t)
