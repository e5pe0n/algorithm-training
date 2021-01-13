N, X = map(int, input().split())
X -= 1
P = [1] * (N + 1)
L = [1] * (N + 1)
for i in range(N):
    P[i + 1] = P[i] * 2 + 1
    L[i + 1] = (2 + 1) + L[i] * 2
res = 0
for i in range(N, -1, - 1):
    if i == 0:
        res += 1
        break
    left = 0
    right = L[i] - 1
    mid = L[i] // 2
    if X == left:
        break
    elif left < X < mid:
        X -= 1
    elif X == mid:
        res += P[i - 1] + 1
        break
    elif mid < X < right:
        res += P[i - 1] + 1
        X -= mid + 1
    else:
        res += P[i]
        break
print(res)
