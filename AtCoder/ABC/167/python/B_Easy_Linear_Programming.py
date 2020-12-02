A, B, C, K = map(int, input().split())
res = min(A, K) - min(C, max(0, K - A - B))
print(res)
