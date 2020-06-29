N = int(input())
L = [0] * (N + 1)


def f(i):
    if i == 0:
        return 2
    if i == 1:
        return 1
    if L[i] == 0:
        L[i] = f(i - 1) + f(i - 2)
    return L[i]


print(f(N))
