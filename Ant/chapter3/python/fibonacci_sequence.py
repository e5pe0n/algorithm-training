M = 10000


def ns(f):
    return next(f).strip()


with open("../testset/fibonacci_sequence/test2.txt", 'r') as f:
    n = int(ns(f))


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


A = [[1, 1], [1, 0]]
A = pow(A, n)
print(A[1][0])
