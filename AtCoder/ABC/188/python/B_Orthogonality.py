N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
p = sum(list(map(lambda x: x[0] * x[1], zip(A, B))))
if p:
    print("No")
else:
    print("Yes")
