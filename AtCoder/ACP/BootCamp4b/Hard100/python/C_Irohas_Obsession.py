INF = int(1e9)


N, K = [int(x) for x in input().split()]
D = [int(x) for x in input().split()] + [0]
idx = 0
V = []
for i in range(10):
    if i == D[idx]:
        idx += 1
    else:
        V.append(i)


def dfs(n):
    if n >= N:
        return n
    ret = INF
    for v in V:
        ret = min(ret, dfs(n * 10 + v))
    return ret


ans = INF
for v in V:
    if v != 0:
        ans = min(ans, dfs(v))
print(ans)
