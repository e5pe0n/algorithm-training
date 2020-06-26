from typing import List


def dfs(R: List[List[int]], N: int, M: int, selected: List[bool], helper_idx: int, j: int) -> float:
    if j >= 5:
        mass = 0
        magic = 0
        for i in range(N):
            if selected[i]:
                mass += R[i][0]
                magic += R[i][1]
        if helper_idx >= N:
            mass += R[helper_idx][0]
            magic += R[helper_idx][1]
        return magic / mass

    max_power = 0.0
    for i in range(N + M):
        if not selected[i]:
            if i >= N:
                for k in range(N, N + M):
                    selected[k] = True
                helper_idx = i
            else:
                selected[i] = True
            max_power = max(max_power, dfs(R, N, M, selected, helper_idx, j + 1))
            if i >= N:
                for k in range(N, N + M):
                    selected[k] = False
                helper_idx = 0
            else:
                selected[i] = False
    return max_power


def solve(V: List[List[int]]):
    N = V[0][0]
    M = V[0][1]
    R = V[1:]

    selected = [False] * (N + M)
    res = dfs(R, N, M, selected, 0, 0)
    print('%.13f' % res)


cases = {
    "case1": [
        [6, 2],
        [10, 30],
        [20, 60],
        [10, 10],
        [30, 100],
        [50, 140],
        [40, 120],
        [10, 3],
        [30, 1],
    ],
    "case2": [
        [6, 2],
        [1, 20],
        [1, 3],
        [32, 100],
        [1, 1],
        [1, 2],
        [2, 5],
        [10, 100],
        [96, 874],
    ]
}

for k, v in cases.items():
    print(f"[{k}]")
    solve(v)
    print()

# [case1]
# 3.0000000000000

# [case2]
# 9.0000000000000
