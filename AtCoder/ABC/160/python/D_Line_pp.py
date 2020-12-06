N, X, Y = map(int, input().split())
X -= 1
Y -= 1
cnt = [0] * N
for i in range(1, N):
    for j in range(i):
        d = min(abs(i - j), abs(X - j) + abs(Y - i) + 1)
        cnt[d] += 1
for c in cnt[1:]:
    print(c)
