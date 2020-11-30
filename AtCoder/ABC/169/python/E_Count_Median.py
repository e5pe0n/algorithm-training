N = int(input())
A, B = [], []
for _ in range(N):
    a, b = map(int, input().split())
    A.append(a)
    B.append(b)

A.sort()
B.sort()
if N % 2 == 0:
    md_A = A[N // 2 - 1] + A[N // 2]
    md_B = B[N // 2 - 1] + B[N // 2]
else:
    md_A = A[N // 2]
    md_B = B[N // 2]
res = md_B - md_A + 1
print(res)
