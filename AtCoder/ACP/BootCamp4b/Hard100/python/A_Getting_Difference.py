N, K = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

found = A.count(K) > 0
A.sort()
max_a = A[-1]
min_diff = A[-1]
for i in range(N - 1):
    diff = A[i + 1] - A[i]
    if diff > 0:
        min_diff = min(min_diff, diff)
if found or (K <= max_a and K % min_diff == 0):
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")
