s = input()
K = int(input())


ans = ""
k = 0


def dfs(_s):
    global ans, k
    if ans != "":
        return
    if _s != "":
        if s.find(_s) < 0:
            return
        else:
            k += 1
            if k == K:
                ans = _s
                return
    for i in range(26):
        dfs(_s + chr(ord('a') + i))


dfs("")
print(ans)
