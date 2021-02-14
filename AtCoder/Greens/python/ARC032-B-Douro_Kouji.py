N, M = map(int, input().split())

par = list(range(N))
rnk = [0] * N


def find(x):
    if par[x] == x:
        return x
    par[x] = find(par[x])
    return par[x]


def unite(x, y):
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


for _ in range(M):
    a, b = map(int, input().split())
    unite(a - 1, b - 1)
st = set()
for i in range(N):
    st.add(find(i))
print(len(st) - 1)
