from pprint import pprint
from typing import Set, Tuple, List


N = 4


def transitive_closure(E: Set[Tuple[int, int]]) -> List[List[List[int]]]:
    global N

    T = [[[i == j or (i, j) in E for j in range(N)] for i in range(N)] for _ in range(N + 1)]

    for k in range(1, N + 1):
        for i in range(N):
            for j in range(N):
                T[k][i][j] = T[k - 1][i][j] or (T[k - 1][i][k - 1] and T[k - 1][k - 1][j])

    return T


E = {
    (3, 0), (3, 2), (1, 3), (1, 2), (2, 1)
}

T = transitive_closure(E)

for k in range(N + 1):
    print('k: %d' % k)
    pprint(T[k])
    print()

# k: 0
# [[True, False, False, False],
#  [False, True, True, True],
#  [False, True, True, False],
#  [True, False, True, True]]

# k: 1
# [[True, False, False, False],
#  [False, True, True, True],
#  [False, True, True, False],
#  [True, False, True, True]]

# k: 2
# [[True, False, False, False],
#  [False, True, True, True],
#  [False, True, True, True],
#  [True, False, True, True]]

# k: 3
# [[True, False, False, False],
#  [False, True, True, True],
#  [False, True, True, True],
#  [True, True, True, True]]

# k: 4
# [[True, False, False, False],
#  [True, True, True, True],
#  [True, True, True, True],
#  [True, True, True, True]]
