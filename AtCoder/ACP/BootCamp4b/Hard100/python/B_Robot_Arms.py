N = int(input())
V = []
for i in range(N):
    X, L = [int(x) for x in input().split()]
    V.append([X + L, X - L])
V.sort()
end = V[0][0]
cnt = 1
for v in V:
    if end <= v[1]:
        cnt += 1
        end = v[0]
print(cnt)
