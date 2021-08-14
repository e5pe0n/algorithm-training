N = int(input())
E = []
for _ in range(N - 1):
    u, v, w = map(int, input().split())
    u -= 1
    v -= 1
    E.append((w, min(u, v), max(u, v)))
E.sort()

par = list(range(N))
rnk = [0] * N
cnt = [1] * N


def find(u):
    if par[u] == u:
        return u
    par[u] = find(par[u])
    return par[u]


def unite(u, v):
    u = find(u)
    v = find(v)
    if u == v:
        return
    if rnk[u] < rnk[v]:
        par[u] = v
    else:
        par[v] = u
        if rnk[u] == rnk[v]:
            rnk[u] += 1
    c = cnt[u] + cnt[v]
    cnt[u] = cnt[v] = c


res = 0
for e in E:
    w, u, v = e
    res += cnt[find(u)] * cnt[find(v)] * w
    unite(u, v)
print(res)
