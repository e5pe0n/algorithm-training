M = 10007


def ns(f):
    return next(f).strip()


with open("../testset/blocks/test2.txt", 'r') as f:
    N = int(ns(f))


def mul(A, B):
    C = [[0] * len(B[0]) for _ in range(len(A))]
    for i in range(len(A)):
        for j in range(len(B[0])):
            for k in range(len(B)):
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M
    return C


def pow(A, n):
    B = [[1 if i == j else 0 for j in range(len(A))] for i in range(len(A))]
    while n > 0:
        if n & 1:
            B = mul(B, A)
        A = mul(A, A)
        n >>= 1
    return B


A = [
    [2, 1, 0],
    [2, 2, 2],
    [0, 1, 2]
]
A = pow(A, N)
print(A[0][0])
