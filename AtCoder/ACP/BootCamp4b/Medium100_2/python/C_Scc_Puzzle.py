N, M = map(int, input().split())
if N <= M // 2:
    res = (N + M // 2) // 2
else:
    res = M // 2
print(res)
