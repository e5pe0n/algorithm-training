from pprint import pprint
from typing import List


INF = 1_000_000_000
N = 5


D = [[[0 for _ in range(N)] for _ in range(N)] for _ in range(N + 1)]
P = [[[-1 for _ in range(N)] for _ in range(N)] for _ in range(N + 1)]
W = [[0 if i == j else INF for j in range(N)] for i in range(N)]


def floyd_warshall(W: List[List[int]]):
    global N, D, P
    for i in range(N):
        for j in range(N):
            D[0][i][j] = W[i][j]
            P[0][i][j] = -1 if i == j or W[i][j] >= INF else i

    for k in range(1, N + 1):
        for i in range(N):
            for j in range(N):
                d = D[k - 1][i][k - 1] + D[k - 1][k - 1][j]
                if d < D[k - 1][i][j]:
                    D[k][i][j] = d
                    P[k][i][j] = P[k - 1][k - 1][j]
                else:
                    D[k][i][j] = D[k - 1][i][j]
                    P[k][i][j] = P[k - 1][i][j]


W[0][1] = 3
W[0][2] = 8
W[0][4] = -4
W[1][3] = 1
W[1][4] = 7
W[2][1] = 4
W[3][2] = -5
W[3][0] = 2
W[4][3] = 6

floyd_warshall(W)

print('# D')
for k in range(N + 1):
    print(f'k: {k}')
    pprint(D[k])
    print()
print()

print('# P')
for k in range(N + 1):
    print(f'k: {k}')
    pprint(P[k])
    print()

# # D
# k: 0
# [[0, 3, 8, 1000000000, -4],
#  [1000000000, 0, 1000000000, 1, 7],
#  [1000000000, 4, 0, 1000000000, 1000000000],
#  [2, 1000000000, -5, 0, 1000000000],
#  [1000000000, 1000000000, 1000000000, 6, 0]]

# k: 1
# [[0, 3, 8, 1000000000, -4],
#  [1000000000, 0, 1000000000, 1, 7],
#  [1000000000, 4, 0, 1000000000, 999999996],
#  [2, 5, -5, 0, -2],
#  [1000000000, 1000000000, 1000000000, 6, 0]]

# k: 2
# [[0, 3, 8, 4, -4],
#  [1000000000, 0, 1000000000, 1, 7],
#  [1000000000, 4, 0, 5, 11],
#  [2, 5, -5, 0, -2],
#  [1000000000, 1000000000, 1000000000, 6, 0]]

# k: 3
# [[0, 3, 8, 4, -4],
#  [1000000000, 0, 1000000000, 1, 7],
#  [1000000000, 4, 0, 5, 11],
#  [2, -1, -5, 0, -2],
#  [1000000000, 1000000000, 1000000000, 6, 0]]

# k: 4
# [[0, 3, -1, 4, -4],
#  [3, 0, -4, 1, -1],
#  [7, 4, 0, 5, 3],
#  [2, -1, -5, 0, -2],
#  [8, 5, 1, 6, 0]]

# k: 5
# [[0, 1, -3, 2, -4],
#  [3, 0, -4, 1, -1],
#  [7, 4, 0, 5, 3],
#  [2, -1, -5, 0, -2],
#  [8, 5, 1, 6, 0]]


# # P
# k: 0
# [[-1, 0, 0, -1, 0],
#  [-1, -1, -1, 1, 1],
#  [-1, 2, -1, -1, -1],
#  [3, -1, 3, -1, -1],
#  [-1, -1, -1, 4, -1]]

# k: 1
# [[-1, 0, 0, -1, 0],
#  [-1, -1, -1, 1, 1],
#  [-1, 2, -1, -1, 0],
#  [3, 0, 3, -1, 0],
#  [-1, -1, -1, 4, -1]]

# k: 2
# [[-1, 0, 0, 1, 0],
#  [-1, -1, -1, 1, 1],
#  [-1, 2, -1, 1, 1],
#  [3, 0, 3, -1, 0],
#  [-1, -1, -1, 4, -1]]

# k: 3
# [[-1, 0, 0, 1, 0],
#  [-1, -1, -1, 1, 1],
#  [-1, 2, -1, 1, 1],
#  [3, 2, 3, -1, 0],
#  [-1, -1, -1, 4, -1]]

# k: 4
# [[-1, 0, 3, 1, 0],
#  [3, -1, 3, 1, 0],
#  [3, 2, -1, 1, 0],
#  [3, 2, 3, -1, 0],
#  [3, 2, 3, 4, -1]]

# k: 5
# [[-1, 2, 3, 4, 0],
#  [3, -1, 3, 1, 0],
#  [3, 2, -1, 1, 0],
#  [3, 2, 3, -1, 0],
#  [3, 2, 3, 4, -1]]
