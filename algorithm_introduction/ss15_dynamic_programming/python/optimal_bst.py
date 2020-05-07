from typing import List
import sys


F_MAX = sys.float_info.max


e = [[F_MAX for _ in range(6)] for _ in range(7)]
w = [[F_MAX for _ in range(6)] for _ in range(7)]
root = [[0 for _ in range(6)] for _ in range(7)]

d_num = 0


def construct_optimal_bst(root: List[List[int]], i: int, j: int, p: int, i_init: int, j_init: int):
    global d_num

    if root[i][j] <= 0:
        if j < p:
            print(f'd{d_num} is left child of k{p}')
        else:
            print(f'd{d_num} is right child of k{p}')
        d_num += 1
        return

    r = root[i][j]
    if i == i_init and j == j_init:
        print(f'k{r} is root')
    elif j < p:
        print(f'k{r} is left child of k{r}')
    else:
        print(f'k{r} is right child of k{r}')

    construct_optimal_bst(root, i, r - 1, r, i_init, j_init)
    construct_optimal_bst(root, r + 1, j, r, i_init, j_init)


def optimal_bst(p: List[float], q: List[float], e: List[List[float]], w: List[List[float]]):
    n = len(p)
    for i in range(1, n + 2):
        e[i][i - 1] = q[i - 1]
        w[i][i - 1] = q[i - 1]

    for l in range(1, n + 1):
        for i in range(1, n - l + 2):
            j = i + l - 1
            w[i][j] = w[i][j - 1] + p[j - 1] + q[j]
            for r in range(i, j + 1):
                t = e[i][r - 1] + e[r + 1][j] + w[i][j]
                if t < e[i][j]:
                    e[i][j] = t
                    root[i][j] = r


p = [0.15, 0.10, 0.05, 0.10, 0.20]
q = [0.05, 0.10, 0.05, 0.05, 0.05, 0.10]

optimal_bst(p, q, e, w)
construct_optimal_bst(root, 1, 5, 0, 1, 5)
