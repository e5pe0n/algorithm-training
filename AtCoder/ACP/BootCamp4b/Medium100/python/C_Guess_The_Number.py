import sys
N, M = list(map(int, input().split()))
A = [-1] * N
flg = True
for i in range(M):
    s, c = list(map(int, input().split()))
    if A[s - 1] == -1 or A[s - 1] == c:
        A[s - 1] = c
    else:
        flg = False
    if N > 1 and s == 1 and c == 0:
        flg = False
if not flg:
    print(-1)
    sys.exit()
if A[0] == -1:
    if N > 1:
        A[0] = 1
    else:
        A[0] = 0
for a in A:
    if a == -1:
        print(0, end='')
    else:
        print(a, end='')
print()
