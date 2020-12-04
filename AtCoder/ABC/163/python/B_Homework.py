N, M = map(int, input().split())
A = sum(map(int, input().split()))
res = max(-1, N - A)
print(res)
