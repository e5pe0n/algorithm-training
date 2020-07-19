N, P = list(map(int, input().split()))
A = list(map(int, input().split()))
NO = 0
NE = 0
for a in A:
    if a % 2 == 0:
        NE += 1
    else:
        NO += 1


def comb(n, k):
    w = min(n - k, k)
    if n <= 1 or w == 0:
        return 1
    a = n
    for i in range(n - 1, n - w, -1):
        a *= i
    b = 1
    for i in range(2, w + 1):
        b *= i
    return a // b


e = 2 ** NE
o = 0
for i in range(P, NO + 1, 2):
    o += comb(NO, i)
if P == 0:
    res = e * o if o > 0 else e
else:
    res = o * e if e > 0 else o
print(res)
