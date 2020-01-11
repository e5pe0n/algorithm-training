def square_matrix_multiply(A, B):
    n = len(A)
    C = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                C[i][j] += A[i][k] * B[k][j]
    return C


def main():
    A = [
        [0, 1],
        [2, 3]
    ]
    B = [
        [4, 5],
        [6, 7]
    ]

    res = square_matrix_multiply(A, B)
    print(res)


if __name__ == '__main__':
    main()
