from typing import List


def solve(V: List[int]):
    N = V[0]
    A = V[1:]

    B = [0] * N
    for i in range(N):
        B[A[i] - 1] += 1

    x = 0
    y = 0
    for i in range(N):
        if B[i] == 0:
            x = i + 1
        elif B[i] == 2:
            y = i + 1

    if x == 0:
        print('Correct')
    else:
        print(f'{y} {x}')


cases = {
    'case1': [6, 1, 5, 6, 3, 2, 6],
    'case2': [7, 5, 4, 3, 2, 7, 6, 1],
}

for k, v in cases.items():
    print(f'[{k}]')
    solve(v)
    print()

# [case1]
# 6 4

# [case2]
# Correct
