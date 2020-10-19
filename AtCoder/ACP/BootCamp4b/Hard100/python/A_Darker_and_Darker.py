from collections import deque


H, W = map(int, input().split())
A = [list(input()) for _ in range(H)]
q = deque()
for i in range(H):
    for j in range(W):
        if A[i][j] == '#':
            q.append([i, j, 0])


def valid(i, j):
    return 0 <= i < H and 0 <= j < W and A[i][j] == '.'


ans = 0
while len(q) > 0:
    p = q.popleft()
    i, j, cc = p[0], p[1], p[2]
    if cc > 0 and A[i][j] == '#':
        continue
    A[i][j] = '#'
    ans = cc
    if valid(i - 1, j):
        q.append([i - 1, j, cc + 1])
    if valid(i + 1, j):
        q.append([i + 1, j, cc + 1])
    if valid(i, j - 1):
        q.append([i, j - 1, cc + 1])
    if valid(i, j + 1):
        q.append([i, j + 1, cc + 1])
print(ans)
