N = int(input())

V = []


def loop(i, f, g):
    while f(i):
        yield i
        i = g(i)


for i in loop(1, lambda x: x * x <= N, lambda x: x + 1):
    if N % i == 0:
        V.append(i)
        if N // i != i:
            V.append(N // i)
V.sort()
for v in V:
    print(v)
