H, W, A, B = map(int, input().split())


def dfs(i, bit, a, b):
    if i == H * W:
        return 1
    if bit & (1 << i):
        return dfs(i + 1, bit, a, b)
    res = 0
    if b:
        res += dfs(i + 1, bit | 1 << i, a, b - 1)
    if a:
        if i % W != W - 1 and ~bit & (1 << (i + 1)):
            res += dfs(i + 1, bit | 1 << i | 1 << (i + 1), a - 1, b)
        if i + W < H * W and ~bit & (1 << (i + W)):
            res += dfs(i + 1, bit | 1 << i | 1 << (i + W), a - 1, b)
    return res


print(dfs(0, 0, A, B))
