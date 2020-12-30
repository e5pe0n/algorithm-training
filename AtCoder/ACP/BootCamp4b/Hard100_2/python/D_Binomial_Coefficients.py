N = int(input())
A = sorted(list(map(int, input().split())))

n = A[-1]
k = A[0]
for a in A[:-1]:
    if abs(k - n // 2) >= abs(a - n // 2):
        k = a
print(n, k)
