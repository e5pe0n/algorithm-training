n = int(input())
A = list(map(int, input().split()))
B = [0] * n
j = n // 2
k = 1 if n % 2 == 1 else -1
for i in range(n):
    B[j] = A[i]
    j += k * (i + 1)
    k = -k
for i in range(n):
    print(str(B[i]) + ' ', end='')
print()
