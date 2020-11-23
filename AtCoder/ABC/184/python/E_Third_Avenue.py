from collections import deque


INF = float('inf')
di = [0, 1, 0, -1]
dj = [1, 0, -1, 0]


H, W = map(int, input().split())
A = [list(input()) for _ in range(H)]

T = [[] for _ in range(26)]
used = [False] * 26
for i in range(H):
    for j in range(W):
        if A[i][j] == 'S':
            S = (i, j)
        if A[i][j] == 'G':
            G = (i, j)
        if A[i][j].islower():
            T[ord(A[i][j]) - ord('a')].append((i, j))


def bfs():
    d = [[INF] * W for _ in range(H)]
    d[S[0]][S[1]] = 0
    q = deque([S])
    while len(q) > 0:
        i, j = q.popleft()
        for _di, _dj in zip(di, dj):
            ni = i + _di
            nj = j + _dj
            if 0 <= ni < H and 0 <= nj < W and A[ni][nj] != '#' and d[ni][nj] > d[i][j] + 1:
                d[ni][nj] = d[i][j] + 1
                q.append((ni, nj))
        if A[i][j].islower() and not used[ord(A[i][j]) - ord('a')]:
            for ni, nj in T[ord(A[i][j]) - ord('a')]:
                if d[ni][nj] > d[i][j] + 1:
                    d[ni][nj] = d[i][j] + 1
                    q.append((ni, nj))
            used[ord(A[i][j]) - ord('a')] = True
    res = d[G[0]][G[1]]
    if res == INF:
        res = -1
    return res


print(bfs())
