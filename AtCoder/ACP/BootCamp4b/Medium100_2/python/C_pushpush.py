from collections import deque


N = int(input())
A = list(map(int, input().split()))


B = deque()
for i, a in enumerate(A):
    if i % 2 == 0:
        B.append(a)
    else:
        B.appendleft(a)
if N % 2 == 0:
    print(' '.join(list(map(str, B))))
else:
    print(' '.join(list(map(str, B))[::-1]))
