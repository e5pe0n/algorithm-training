from pprint import pprint
import copy
import math
from typing import List


INF = 1_000_000_000
N = 5

L = [[[0 for _ in range(N)] for _ in range(N)] for _ in range(math.floor(math.log2(N - 1)) + 1)]
W = [[0 if i == j else INF for j in range(N)] for i in range(N)]


def extend_shortest_paths(L_: List[List[int]], W: List[List[int]]) -> List[List[int]]:
    n = len(W)
    new_L_ = copy.deepcopy(L_)

    for i in range(n):
        for j in range(n):
            new_L_[i][j] = INF
            for k in range(n):
                new_L_[i][j] = min(new_L_[i][j], L_[i][k] + W[k][j])

    return new_L_


def faster_all_pairs_shortest_paths(W: List[List[int]]):
    global L

    L[0] = copy.deepcopy(W)
    idx = 0
    m = 1
    while m < N - 1:
        L[idx + 1] = extend_shortest_paths(L[idx], L[idx])
        idx += 1
        m *= 2


W[0][1] = 3
W[0][2] = 8
W[0][4] = -4
W[1][3] = 1
W[1][4] = 7
W[2][1] = 4
W[3][0] = 2
W[3][2] = -5
W[4][3] = 6

faster_all_pairs_shortest_paths(W)

for m, L_ in enumerate(L):
    print('m = %d' % m)
    pprint(L_)
    print()

# m = 0
# [[0, 3, 8, 1000000000, -4],
#  [1000000000, 0, 1000000000, 1, 7],
#  [1000000000, 4, 0, 1000000000, 1000000000],
#  [2, 1000000000, -5, 0, 1000000000],
#  [1000000000, 1000000000, 1000000000, 6, 0]]

# m = 1
# [[0, 3, 8, 2, -4],
#  [3, 0, -4, 1, 7],
#  [1000000000, 4, 0, 5, 11],
#  [2, -1, -5, 0, -2],
#  [8, 1000000000, 1, 6, 0]]

# m = 2
# [[0, 1, -3, 2, -4],
#  [3, 0, -4, 1, -1],
#  [7, 4, 0, 5, 3],
#  [2, -1, -5, 0, -2],
#  [8, 5, 1, 6, 0]]
