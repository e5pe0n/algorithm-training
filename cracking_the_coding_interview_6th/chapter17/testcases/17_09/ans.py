def ns(f):
    return next(f).strip()


with open("02.txt") as f:
    n, k = map(int, ns(f).split())
    ps = list(map(int, ns(f).split()))


s = set()


def dfs(ps, idx, m):
    global s
    if idx == len(ps):
        s.add(m)
        return
    for i in range(k + 1):
        dfs(ps, idx + 1, m * ps[idx]**i)


dfs(ps, 0, 1)
s = sorted(list(s))
print(s[k - 1])
