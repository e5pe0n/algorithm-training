X, K, D = map(int, input().split())
X = abs(X)
k = min(K, X // D)
K -= k
X -= k * D
if K % 2 == 0:
    print(X)
else:
    print(D - X)
