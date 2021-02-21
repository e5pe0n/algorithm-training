S = input().split()
N = int(input())
T = [input() for _ in range(N)]
for i, s in enumerate(S):
    for j, t in enumerate(T):
        if len(s) != len(t):
            continue
        f = True
        for _s, _t in zip(s, t):
            if _s != _t and _t != '*':
                f = False
                break
        if f:
            S[i] = '*' * len(s)
            break
print(' '.join(S))
