N = int(input())
A = list(map(int, input().split()))
for i, a in enumerate(A.copy(), 1):
    A[a - 1] = i
for a in A:
    print(str(a) + ' ', end='')
print()
