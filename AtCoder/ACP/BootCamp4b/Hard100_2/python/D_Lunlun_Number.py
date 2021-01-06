from sys import setrecursionlimit
setrecursionlimit(10**9)


K = int(input())
cnt = 0


def dfs(s, n):
    global cnt
    if len(s) >= n:
        cnt += 1
        if cnt == K:
            return int(s)
        else:
            return 0
    res = 0
    if s == "":
        for i in range(1, 10):
            res += dfs(str(i), n)
    else:
        last = int(s[-1])
        for i in range(max(0, last - 1), min(9, last + 1) + 1):
            res += dfs(s + str(i), n)
    return res


res = 0
for i in range(1, 10**6):
    if (res := dfs("", i)) > 0:
        print(res)
        exit()
