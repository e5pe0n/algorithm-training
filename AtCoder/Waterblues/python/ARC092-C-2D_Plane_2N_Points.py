from functools import cmp_to_key

N = int(input())
AB = [list(map(int, input().split())) for _ in range(N)]
CD = [list(map(int, input().split())) for _ in range(N)]


def cmp(x, y):
    if x[1] == y[1]:
        if x[0] < y[0]:
            return -1
        elif x[0] == y[0]:
            return 0
        else:
            return 1
    elif x[1] < y[1]:
        return -1
    else:
        return 1


CD.sort(key=cmp_to_key(cmp))
used = [False] * N
for c, d in CD:
    _j, _x = -1, -1
    for j, (a, b) in enumerate(AB):
        if not used[j] and a < c and b < d:
            if a > _x:
                _j = j
                _x = a
    if _j >= 0:
        used[_j] = True

res = len(list(filter(lambda x: x, used)))
print(res)
