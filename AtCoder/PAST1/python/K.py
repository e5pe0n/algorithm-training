from typing import List


def solve(V: List):
    N = V[0]
    P = V[1]
    Q = V[2]
    C = V[3:]

    for c in C:
        p = P[c[0] - 1]
        while p != -1 and p != c[1]:
            p = P[p - 1]
        if p == c[1]:
            print('Yes')
        else:
            print('No')


cases = {
    "case1": [
        7,
        [-1, 1, 1, 2, 2, 3, 3],
        6,
        [7, 1],
        [4, 1],
        [2, 3],
        [5, 1],
        [5, 2],
        [2, 5]
    ],
    "case2": [
        20,
        [4, 11, 12, -1, 1, 13, 13, 4, 6, 20, 1, 1, 20, 10, 8, 8, 20, 10, 18, 1],
        20,
        [18, 14],
        [11, 3],
        [2, 13],
        [13, 11],
        [10, 15],
        [9, 5],
        [17, 11],
        [18, 10],
        [1, 16],
        [9, 4],
        [19, 6],
        [5, 10],
        [17, 8],
        [15, 8],
        [5, 16],
        [6, 20],
        [3, 19],
        [10, 12],
        [5, 13],
        [18, 1],
    ]
}

for k, v in cases.items():
    print(f'[{k}]')
    solve(v)
    print()

# [case1]
# Yes
# Yes
# No
# Yes
# Yes
# No

# [case2]
# No
# No
# No
# No
# No
# No
# No
# Yes
# No
# Yes
# No
# No
# No
# Yes
# No
# Yes
# No
# No
# No
# Yes
