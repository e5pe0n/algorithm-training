N, D, K = map(int, input().split())
LR = [list(map(int, input().split())) for _ in range(D)]
ST = [list(map(int, input().split())) for _ in range(K)]
P = list(map(lambda x: x[0], ST))
res = [0] * K

for i, (L, R) in enumerate(LR):
    for j, (S, T) in enumerate(ST):
        if L <= P[j] <= R:
            if S < T and P[j] < T:
                P[j] = R
                if P[j] >= T:
                    res[j] = i + 1
            elif S > T and P[j] > T:
                P[j] = L
                if P[j] <= T:
                    res[j] = i + 1
print('\n'.join(list(map(str, res))))
