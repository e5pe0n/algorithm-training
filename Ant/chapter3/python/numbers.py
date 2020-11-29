MOD = 1000


def ns(f):
    return next(f).strip()


with open("../testset/numbers/test2.txt", 'r') as f:
    n = int(ns(f))


def mul(A, B):
    C = [[0] * len(B[0]) for _ in range(len(A))]
    for i in range(len(A)):
        for j in range(len(B[0])):
            for k in range(len(B)):
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD
    return C


def pow(A, n):
    res = [[1 if i == j else 0 for j in range(len(A))] for i in range(len(A))]
    while n > 0:
        if n & 1:
            res = mul(res, A)
        A = mul(A, A)
        n >>= 1
    return res


A = [
    [3, 5],
    [1, 3]
]
A = pow(A, n)
print(f"{(A[0][0] * 2 - 1 + MOD) % MOD:03d}")
