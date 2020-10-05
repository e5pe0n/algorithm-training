K, T = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
A.sort()
ans = max(0, A[T - 1] - sum(A[:-1]) - 1)
print(ans)
