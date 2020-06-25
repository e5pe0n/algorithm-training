from copy import deepcopy
from typing import List


def solve(V: List):
    N = V[0][0]
    Q = V[0][1]

    F = [['N' for _ in range(N)] for _ in range(N)]
    _F = [['N' for _ in range(N)] for _ in range(N)]

    for s in V[1:]:
        s = [int(s) for s in s.split()]
        if s[0] == 1:
            _F[s[1] - 1][s[2] - 1] = 'Y'
        elif s[0] == 2:
            for i in range(N):
                if F[i][s[1] - 1] == 'Y':
                    _F[s[1] - 1][i] = 'Y'
        else:
            for j in range(N):
                if F[s[1] - 1][j] == 'Y':
                    for k in range(N):
                        if F[j][k] == 'Y':
                            _F[s[1] - 1][k] = 'Y'
        F = deepcopy(_F)

    res = '\n'.join([''.join(f) for f in F])
    print(res)


v = [
    [6, 7],
    '1 1 2',
    '1 2 3',
    '1 3 4',
    '1 1 5',
    '1 5 6',
    '3 1',
    '2 6'
]

solve(v)
