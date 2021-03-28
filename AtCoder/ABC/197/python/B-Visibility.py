H, W, X, Y = map(int, input().split())
X -= 1
Y -= 1
S = [list(input()) for _ in range(H)]

res = 0
for j in range(Y, -1, -1):
    if S[X][j] == '#':
        break
    res += 1
for j in range(Y, W):
    if S[X][j] == '#':
        break
    res += 1

for i in range(X, -1, -1):
    if S[i][Y] == '#':
        break
    res += 1
for i in range(X, H):
    if S[i][Y] == '#':
        break
    res += 1
print(res - 3)
