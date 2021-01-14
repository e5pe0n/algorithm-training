N = int(input())


def dfs(s, max_c):
    if len(s) == N:
        print(s)
        return
    for c in range(ord('a'), max_c + 2):
        dfs(s + chr(c), max(c, max_c))


dfs("a", ord('a'))
