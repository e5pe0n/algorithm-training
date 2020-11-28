from decimal import *
getcontext().prec = 28
n = int(input())
_n = int(Decimal(4 * (n + 1)) / Decimal(1 + (1 + 8 * (n + 1)) ** 0.5))
print(1 + n - _n)
