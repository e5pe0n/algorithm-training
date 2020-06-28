N = int(input())
A = [int(input()) for _ in range(N)]
selected = [False for _ in range(N)]

a = 1
cnt = 0
while a != 2 and not selected[a - 1]:
    selected[a - 1] = True
    a = A[a - 1]
    cnt += 1
if a == 2:
    print(cnt)
else:
    print('-1')
