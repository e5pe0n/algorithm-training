def dfs(n_str, N):
    if n_str != "" and int(n_str) > N:
        return 0
    ret = int(all(c in n_str for c in "357"))
    for c in "357":
        ret += dfs(n_str + c, N)
    return ret


N = int(input())
ans = dfs("", N)
print(ans)
