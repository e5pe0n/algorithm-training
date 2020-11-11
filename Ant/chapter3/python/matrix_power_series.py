def ns(f):
    return next(f).strip()


with open("../testset/matrix_power_series/test1.txt", 'r') as f:
    n, k, M = map(int, ns(f).split())
    A = [list(map(int, ns(f).split())) for _ in range(n)]
    B = [[0] * (n * 2) for _ in range(n * 2)]
    for i in range(n):
        for j in range(n):
            B[i][j] = A[i][j]
        B[n + i][i] = B[n + i][n + i] = 1


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


B = pow(B, k + 1)
for i in range(n):
    for j in range(n):
        a = B[n + i][j]
        if i == j:
            a = (a + M - 1) % M
        if j == n - 1:
            print(a)
        else:
            print(a, '', end='')
