N = int(input())


V = []


def dfs(s, max_c):
    global V
    if len(s) == N:
        V.append(s)
        return
    for c in range(ord('a'), ord(max_c) + 2):
        dfs(s + chr(c), max(max_c, chr(c)))


dfs("a", 'a')
for v in V:
    print(v)
