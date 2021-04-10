from copy import deepcopy


def rotate1(m):
    # ccw
    n = len(m)
    res = [[None] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            res[n - j - 1][i] = m[i][j]
    return res


def rotate2(m):
    # ccw
    # in place
    # O(n^2)
    n = len(m)
    for i in range(n // 2):
        w = n - i - 1
        for j in range(i, w):
            src_i, src_j = i, j
            src = m[src_i][src_j]
            for k in range(4):
                dst_i = w - (src_j - i)
                dst_j = src_i
                dst = m[dst_i][dst_j]
                m[dst_i][dst_j] = src
                src = dst
                src_i, src_j = dst_i, dst_j


def rotate3(m):
    # cw
    # in place
    # O(n^2)
    if len(m) == 0 or len(m) != len(m[0]):
        return False
    n = len(m)
    for layer in range(n // 2):
        fst = layer
        lst = n - 1 - layer
        for i in range(fst, lst):
            offset = i - fst
            top = m[fst][i]  # save top

            # left -> top
            m[fst][i] = m[lst - offset][fst]

            # bottom -> left
            m[lst - offset][fst] = m[lst][lst - offset]

            # right -> bottom
            m[lst][lst - offset] = m[i][lst]

            # top -> right
            m[i][lst] = top
    return True


def show1(f, fn, m):
    print(f"# {fn}")
    res = f(m)
    print("\n".join("".join(s) for s in res))
    print()


def show2(f, fn, m):
    print(f"# {fn}")
    m2 = deepcopy(m)
    f(m2)
    print("\n".join("".join(s) for s in m2))
    print()


def ns(f):
    return next(f).strip()


with open("../testcases/1_07_1.txt") as f:
    h, w = map(int, ns(f).split())
    m = [list(ns(f)) for _ in range(h)]


show1(rotate1, "rotate1", m)
show2(rotate2, "rotate2", m)
show2(rotate3, "rotate3", m)
