S = input()
K = int(input())


def dfs(s):
    global K
    if K <= 0:
        return ""
    if s in S:
        K -= 1
        if K == 0:
            return s
    else:
        return ""
    res = ""
    for c in range(ord('a'), ord('z') + 1):
        res += dfs(s + chr(c))
    return res


for c in range(ord('a'), ord('z') + 1):
    if res := dfs(chr(c)):
        print(res)
        exit()
