EPS = 1e-10


A, B = input().split()
A = int(A)
B = float(B)
b = int(B * 100 + EPS)
res = A * b // 100
print(res)
