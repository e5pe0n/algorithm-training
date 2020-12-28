from collections import Counter
N, X, Y = map(int, input().split())
X -= 1
Y -= 1
C = Counter()
for i in range(N - 1):
    for j in range(i + 1, N):
        d = min(j - i, abs(X - i) + abs(Y - j) + 1)
        C[d] += 1
for i in range(1, N):
    print(C[i])
