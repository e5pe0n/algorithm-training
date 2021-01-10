N = int(input())
A = list(map(int, input().split()))
N = 1 << N
left = max(A[:N // 2])
right = max(A[N // 2:])
res = 0
if left > right:
    res = A.index(right)
else:
    res = A.index(left)
print(res + 1)
