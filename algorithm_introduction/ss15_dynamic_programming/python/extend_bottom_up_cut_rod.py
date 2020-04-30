from typing import List, Tuple


def extend_bottom_up_cut_rod(p: List[int], n: int) -> Tuple[List[int], List[int]]:
    r = [0] * 40
    s = [0] * 40
    for j in range(1, n + 1):
        for i in range(1, j + 1):
            if r[j] < p[i - 1] + r[j - i]:
                r[j] = p[i - 1] + r[j - i]
                s[j] = i
    return r, s


def print_cut_rod_solution(p: List[int], n: int):
    r, s = extend_bottom_up_cut_rod(p, n)
    sol = []
    i = n
    while i > 0:
        sol.append(s[i])
        i -= s[i]
    print(f'n: {n}, sol: {sol}')


p = [0] * 40
q = [1, 5, 8, 9, 10, 17, 17, 20, 24, 30]
for i in range(len(q)):
    p[i] = q[i]

for i in range(1, 11):
    print_cut_rod_solution(p, i)

"""
n: 1, sol: [1]
n: 2, sol: [2]
n: 3, sol: [3]
n: 4, sol: [2, 2]
n: 5, sol: [2, 3]
n: 6, sol: [6]
n: 7, sol: [1, 6]
n: 8, sol: [2, 6]
n: 9, sol: [3, 6]
n: 10, sol: [10]
"""
