from collections import Counter
MOD = 998244353
N = int(input())
D = list(map(int, input().split()))


def mod_pow(x, n):
    res = 1
    while n > 0:
        if n & 1:
            res = res * x % MOD
        x = x * x % MOD
        n >>= 1
    return res


if D[0] != 0:
    print(0)
    exit()
C = Counter(D)
if C[0] != 1:
    print(0)
    exit()
res = 1
prv = 0
prv_cnt = 1
for k, v in sorted(C.most_common())[1:]:
    if k - prv != 1:
        res = 0
        break
    res = res * mod_pow(prv_cnt, v) % MOD
    prv = k
    prv_cnt = v
print(res)
