A, B, N = map(int, input().split())


def f(x):
    return A * x // B - A * (x // B)


print(f(min(B - 1, N)))
