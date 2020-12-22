from collections import deque
INF = float('inf')

H, W = map(int, input().split())
S = [list(input()) for _ in range(H)]
C = [[INF] * W for _ in range(H)]


def bfs():
    global C
    C[0][0] = int(S[0][0] == '#')
    q = deque([(0, 0)])
    while len(q) > 0:
        i, j = q.popleft()
        if i + 1 < H and C[i + 1][j] > C[i][j] + int(S[i][j] == '.' and S[i + 1][j] == '#'):
            C[i + 1][j] = C[i][j] + int(S[i][j] == '.' and S[i + 1][j] == '#')
            q.append((i + 1, j))
        if j + 1 < W and C[i][j + 1] > C[i][j] + int(S[i][j] == '.' and S[i][j + 1] == '#'):
            C[i][j + 1] = C[i][j] + int(S[i][j] == '.' and S[i][j + 1] == '#')
            q.append((i, j + 1))


bfs()
print(C[-1][-1])
