def dfs(n, N):
    if n > N:
        return 0
    ret = int(n <= N)
    for i in range(10):
        ret += dfs(int(str(n)[:-1] + str(i) + str(n)[-1]), N)
    return ret


N = int(input())
C = [[0] * 10 for _ in range(10)]
for i in range(1, 10):
    for j in range(1, 10):
        C[i][j] += int(i == j)
        C[i][j] += dfs(j * 10 + i, N)
ans = 0
for i in range(11, N + 1):
    ans += C[int(str(i)[0])][int(str(i)[-1])]
for i in range(1, min(9, N) + 1):
    ans += C[i][i]
print(ans)
