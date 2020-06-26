from typing import List, Tuple


INF = 1_000_000_000


def dfs(R: List[Tuple[str, int]], N: int, M: int, selected: List[bool], cost: int, j: int) -> int:
    if j >= N:
        return cost

    min_cost = INF
    for i in range(M):
        if R[i][0][j] == 'Y':
            _selected = selected.copy()
            _cost = cost
            if not selected[i]:
                _cost += R[i][1]
                _selected[i] = True
            _cost = dfs(R, N, M, _selected, _cost, j + 1)
            min_cost = min(min_cost, _cost)
    return min_cost


def solve(V: List):
    N = V[0][0]
    M = V[0][1]
    R = [(v.split()[0], int(v.split()[1])) for v in V[1:]]

    selected = [False] * M
    cost = dfs(R, N, M, selected, 0, 0)
    if cost >= INF:
        print(-1)
    else:
        print(cost)


cases = {
    'case1': [
        [3, 4],
        'YYY 100',
        'YYN 20',
        'YNY 10',
        'NYY 25'
    ],
    'case2': [
        [5, 4],
        'YNNNN 10',
        'NYNNN 10',
        'NNYNN 10',
        'NNNYN 10',
    ],
    'case3': [
        [10, 14],
        'YNNYNNNYYN 774472905',
        'YYNNNNNYYY 75967554',
        'NNNNNNNNNN 829389188',
        'NNNNYYNNNN 157257407',
        'YNNYNNYNNN 233604939',
        'NYYNNNNNYY 40099278',
        'NNNNYNNNNN 599672237',
        'NNNYNNNNYY 511018842',
        'NNNYNNYNYN 883299962',
        'NNNNNNNNYN 883093359',
        'NNNNNYNYNY 54742561',
        'NYNNYYYNNY 386272705',
        'NNNNYYNNNN 565075143',
        'NNYNYNNNYN 123300589',
    ]
}

for k, v in cases.items():
    print(f'[{k}]')
    solve(v)
    print()

# [case1]
# 30

# [case2]
# -1

# [case3]
# 451747367
