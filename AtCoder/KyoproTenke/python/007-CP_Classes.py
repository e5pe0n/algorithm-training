from bisect import bisect_left

N = int(input())
A = sorted(list(map(int, input().split())))

Q = int(input())
for _ in range(Q):
    B = int(input())
    idx = bisect_left(A, B)
    if idx == N:
        res = abs(A[idx - 1] - B)
    elif idx == 0:
        res = abs(A[idx] - B)
    else:
        res = min(abs(A[idx] - B), abs(A[idx - 1] - B))
    print(res)
