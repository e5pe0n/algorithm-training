H, W = map(int, input().split())
S = [list(input()) for _ in range(H)]

res = 0
for i in range(H - 1):
    for j in range(W - 1):
        cnt = 0
        for dx, dy in [(0, 0), (0, 1), (1, 0), (1, 1)]:
            x = i + dx
            y = j + dy
            if S[x][y] == '#':
                cnt += 1
        if cnt == 1 or cnt == 3:
            res += 1
print(res)
