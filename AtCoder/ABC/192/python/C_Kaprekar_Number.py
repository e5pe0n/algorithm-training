N, K = map(int, input().split())


def g1(n):
    s = list(str(n))
    s.sort(reverse=True)
    return int(''.join(s))


def g2(n):
    s = list(str(n))
    s.sort()
    return int(''.join(s))


def f(n):
    return g1(n) - g2(n)


res = N
for i in range(K):
    res = f(res)
print(res)
