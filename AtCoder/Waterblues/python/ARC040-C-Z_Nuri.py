N = int(input())
S = [list(input()) for _ in range(N)]

res = 0
for i in range(N):
    last = -1
    for j in range(N):
        if S[i][j] == '.':
            last = j
    if last < 0:
        continue
    for j in range(last + 1):
        S[i][j] = 'o'
    for j in range(last, N):
        if i + 1 < N:
            S[i + 1][j] = 'o'
    res += 1
print(res)
