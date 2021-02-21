from functools import cmp_to_key

_B = list(map(int, input().split()))
B = [0] * 10
for i, _b in enumerate(_B):
    B[_b] = i
N = int(input())


def comp(x, y):
    s = str(x)
    t = str(y)
    if len(s) == len(t):
        for _s, _t in zip(s, t):
            if _s == _t:
                continue
            if B[int(_s)] < B[int(_t)]:
                return -1
            elif B[int(_s)] > B[int(_t)]:
                return 1
        return 0
    if len(s) < len(t):
        return -1
    else:
        return 1


A = sorted([int(input()) for _ in range(N)], key=cmp_to_key(comp))
print('\n'.join(list(map(str, A))))
