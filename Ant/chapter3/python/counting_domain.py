from collections import deque


def ns(f):
    return next(f).strip()


with open("../testset/counting_domain/test3.txt", 'r') as f:
    W, H, N = map(int, ns(f).split())
    X1 = list(map(lambda x: int(x) - 1, ns(f).split()))
    X2 = list(map(lambda x: int(x) - 1, ns(f).split()))
    Y1 = list(map(lambda x: int(x) - 1, ns(f).split()))
    Y2 = list(map(lambda x: int(x) - 1, ns(f).split()))


dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]


def compress(x1, x2, w):
    xs = []
    for i in range(N):
        for d in range(-1, 2):
            tx1 = x1[i] + d
            tx2 = x2[i] + d
            if 0 <= tx1 < w:
                xs.append(tx1)
            if 0 <= tx2 < w:
                xs.append(tx2)
    xs = list(set(xs))
    for i in range(N):
        x1[i] = xs.index(x1[i])
        x2[i] = xs.index(x2[i])
    return len(xs)


W = compress(X1, X2, W)
H = compress(Y1, Y2, H)

field = [[False] * W for _ in range(H)]
for i in range(N):
    for y in range(Y1[i], Y2[i] + 1):
        for x in range(X1[i], X2[i] + 1):
            field[y][x] = True

for i in range(H):
    for j in range(W):
        print(int(field[i][j]), end='')
    print()

ans = 0
for y in range(H):
    for x in range(W):
        if field[y][x]:
            continue
        ans += 1
        field[y][x] = True
        q = deque([[x, y]])
        while len(q) > 0:
            sx, sy = q.popleft()
            for i in range(4):
                tx = sx + dx[i]
                ty = sy + dy[i]
                if 0 <= tx < W and 0 <= ty < H and not field[ty][tx]:
                    q.append([tx, ty])
                    field[ty][tx] = True
print(ans)
