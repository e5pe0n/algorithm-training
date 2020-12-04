N, M = map(int, input().split())
A = list(map(int, input().split()))
a = sum(A)
t = len(list(filter(lambda x: 4 * M * x >= a, A)))
if t >= M:
    print("Yes")
else:
    print("No")
