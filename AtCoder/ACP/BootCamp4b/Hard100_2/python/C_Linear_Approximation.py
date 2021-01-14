N = int(input())
A = sorted([int(v) - i - 1 for i, v in enumerate(input().split())])
mid_idx = N // 2
res = sum(list(map(lambda x: abs(x - A[mid_idx]), A)))
if N % 2 == 0:
    res = min(res, sum(list(map(lambda x: abs(x - A[mid_idx + 1]), A))))
print(res)
