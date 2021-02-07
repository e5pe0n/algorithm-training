N = int(input())
P = list(map(int, input().split()))
B = [0] * (N + 1)


def sm(i):
    global B
    s = 0
    while i > 0:
        s += B[i]
        i -= i & -i
    return s


def add(i, diff):
    while i <= N:
        B[i] += diff
        i += i & -i


res = [0] * N
s = 0
for i in range(N):
    t = i - sm(P[i])
    res[i] = t
    s += t
    add(P[i], 1)
if s != N - 1:
    print("-1")
    exit()
used = [False] * N
res2 = []
for i in range(N):
    t = res[i]
    cnt = 0
    while t > 0:
        _i = i - cnt
        if used[_i]:
            print("-1")
            exit()
        used[_i] = True
        res2.append(_i)
        cnt += 1
        t -= 1
print('\n'.join(list(map(str, res2))))
