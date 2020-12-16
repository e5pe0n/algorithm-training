MAX_S = 10**9
N, K, S = map(int, input().split())


def f(i):
    a = S
    if i >= K:
        a = MAX_S
        if S == MAX_S:
            a -= 1
    return a


A = [str(f(i)) for i in range(N)]
print(' '.join(A))
