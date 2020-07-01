import sys


N, K = [int(i) for i in input().split()]
A = [int(i) for i in input().split()]

for i in range(1 << N):
    bs = format(i, '08b')[::-1]  # index of string begin from left
    s = 0
    for j in range(N):
        if bs[j] == '1':
            s += A[j]
    if s == K:
        print('YES')
        sys.exit()
print('NO')
