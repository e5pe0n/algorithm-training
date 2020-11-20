import sys
INF = 1_000_000_001
N = int(input())
A = input().split()
n = INF
for a in A:
    a = int(a)
    if a % 2 != 0:
        print(0)
        sys.exit()
    cnt = 0
    while a % 2 == 0:
        a = a >> 1
        cnt += 1
    n = min(n, cnt)
print(n)
