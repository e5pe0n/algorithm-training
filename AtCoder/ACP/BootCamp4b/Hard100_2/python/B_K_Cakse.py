K, T = map(int, input().split())
A = list(map(int, input().split()))
res = max(0, max(A) - 1 - (sum(A) - max(A)))
print(res)
