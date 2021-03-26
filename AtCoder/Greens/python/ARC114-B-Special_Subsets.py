MOD = 998244353
N = int(input())
F = list(map(lambda x: int(x) - 1, input().split()))

par = list(range(N))
rnk = [0] * N


def find(x):
    global par
    if par[x] == x:
        return x
    par[x] = find(par[x])
    return par[x]


def unite(x, y):
    global par, rnk
    x = find(x)
    y = find(y)
    if x == y:
        return
    if rnk[x] < rnk[y]:
        par[x] = y
    else:
        par[y] = x
        if rnk[x] == rnk[y]:
            rnk[x] += 1


for i in range(N):
    unite(i, F[i])

st = set()
for i in range(N):
    st.add(find(i))


def mod_pow(x, n):
    res = 1
    while n > 0:
        if n & 1:
            res = res * x % MOD
        x = x * x % MOD
        n >>= 1
    return res


res = mod_pow(2, len(st)) - 1
print(res)
