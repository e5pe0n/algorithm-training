H, W, K = [int(x) for x in input().split()]
S = [input() for _ in range(H)]
A = [[0] * W for _ in range(H)]

M = {}
for i in range(H):
    for j in range(W):
        if S[i][j] == '#':
            M.setdefault(j, []).append(i)
X = sorted(list(M.keys()))
X.append(W)
X.append(W)
left = 0
right_it = iter(X[1:])
right = next(right_it)
n = 0
for x in X[:-2]:
    n += 1
    Y = M[x]
    Y.sort()
    Y.append(H)
    bottom_it = iter(Y[1:])
    bottom = next(bottom_it)
    for i in range(H):
        if i == bottom:
            n += 1
            bottom = next(bottom_it)
        for j in range(left, right):
            A[i][j] = str(n)
    left = right
    right = next(right_it)

for a in A:
    print(" ".join(a))
