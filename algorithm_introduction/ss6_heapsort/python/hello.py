from array import array


def main(A):
    A[0], A[1] = A[1], A[0]


if __name__ == '__main__':
    A = array('I', [1, 2, 3])
    main(A)
    print(A)
