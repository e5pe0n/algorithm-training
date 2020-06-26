from typing import List


def solve(V: List):
    N = V[0]
    C = V[1]
    Q = V[2]
    S = V[3:]

    cnt = 0
    for s in S:
        s = [int(s) for s in s.split()]
        if s[0] == 1:
            if C[s[1] - 1] - s[2] >= 0:
                C[s[1] - 1] -= s[2]
                cnt += s[2]
        elif s[0] == 2:
            flg = True
            for i in range(0, N, 2):
                if C[i] - s[1] < 0:
                    flg = False
                    break
            if flg:
                for i in range(0, N, 2):
                    C[i] -= s[1]
                    cnt += s[1]
        else:
            flg = True
            for i in range(N):
                if C[i] - s[1] < 0:
                    flg = False
                    break
            if flg:
                for i in range(N):
                    C[i] -= s[1]
                    cnt += s[1]

    print(cnt)


cases = {
    'case1': [
        4,
        [5, 3, 3, 5],
        6,
        "1 2 1",
        "2 2",
        "2 2",
        "3 100",
        "3 1",
        "1 1 3"
    ],
    'case2': [
        10,
        [241, 310, 105, 738, 405, 490, 158, 92, 68, 20],
        20,
        "2 252",
        "1 4 36",
        "2 69",
        "1 5 406",
        "3 252",
        "1 3 8",
        "1 10 10",
        "3 11",
        "1 4 703",
        "3 1",
        "2 350",
        "3 10",
        "2 62",
        "2 3",
        "2 274",
        "1 2 1",
        "3 126",
        "1 4 702",
        "3 6",
        "2 174"
    ],
    'case3': [
        2,
        [3, 4],
        3,
        "1 2 9",
        "2 4",
        "3 4"
    ]
}

for k, v in cases.items():
    print(f'[{k}]')
    solve(v)
    print()

# [case1]
# 9

# [case2]
# 390

# [case3]
# 0
