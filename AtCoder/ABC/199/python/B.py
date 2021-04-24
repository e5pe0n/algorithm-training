N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

cnt = 0
for x in range(1, 1000 + 1):
    if all(map(lambda y: y[0] <= x <= y[1], zip(A, B))):
        cnt += 1
print(cnt)
