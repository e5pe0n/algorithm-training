# probably logic is right but out of allowed memory
import sys
MAX_N = 100_001
N = int(input())
X = []
Y = []
T = []
for i in range(N):
    t, x, y = [int(i) for i in input().split()]
    X.append(x)
    Y.append(y)
    T.append(t)

C = [[[False] * MAX_N for _ in range(MAX_N)] for _ in range(2)]  # memory over
C[0][0][0] = True
i = 0
for t in range(1, T[N - 1] + 1):
    _t = t % 2
    for j in range(N + 1):
        for k in range(N + 1):
            _tt = (t - 1) % 2
            C[_t][j][k] = (j - 1 >= 0 and C[_tt][j - 1][k]) or (j + 1 <= N and C[_tt][j + 1][k]
                                                                ) or (k - 1 >= 0 and C[_tt][j][k - 1]) or (k + 1 <= N and C[_tt][j][k + 1])
    if t == T[i]:
        if not C[_t][X[i]][Y[i]]:
            print('No')
            sys.exit()
        i += 1
print('Yes')
