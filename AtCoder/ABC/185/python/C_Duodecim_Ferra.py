L = int(input())


def com(n, k):
    x = n
    for i in range(n - 1, n - k, -1):
        x *= i
    y = k
    for i in range(k - 1, 0, -1):
        y *= i
    return x // y


res = com(L - 1, 11)
print(res)
