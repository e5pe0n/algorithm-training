M = 10007


def ns(f):
    return next(f).strip()


with open("../testset/num_of_len_k_paths_of_graph/test1.txt", 'r') as f:
    n, k = map(int, ns(f).split())
    G = [list(map(int, ns(f).split())) for _ in range(n)]


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


G = pow(G, k)
print(sum(map(sum, G)))
