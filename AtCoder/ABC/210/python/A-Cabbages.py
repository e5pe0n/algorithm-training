N, A, X, Y = map(int, input().split())

res = min(A, N) * X + max(0, N - A) * Y
print(res)
