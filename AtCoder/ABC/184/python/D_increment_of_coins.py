A, B, C = map(int, input().split())

N = 101
dp = [[[0.0] * N for _ in range(N)] for _ in range(N)]


def f(a, b, c):
    global dp
    if a >= 100 or b >= 100 or c >= 100:
        return 0.0
    res = 0.0
    t = a + b + c
    if dp[a + 1][b][c] == 0.0:
        dp[a + 1][b][c] = f(a + 1, b, c)
    res += (dp[a + 1][b][c] + 1) * a / t
    if dp[a][b + 1][c] == 0.0:
        dp[a][b + 1][c] = f(a, b + 1, c)
    res += (dp[a][b + 1][c] + 1) * b / t
    if dp[a][b][c + 1] == 0.0:
        dp[a][b][c + 1] = f(a, b, c + 1)
    res += (dp[a][b][c + 1] + 1) * c / t
    return res


print(f"{f(A, B, C):.7f}")
