import sys
N, M = list(map(int, input().split()))
S = set()
B = [False] * (N + 1)
for i in range(M):
    a, b = list(map(int, input().split()))
    if a == 1:
        S.add(b)
    elif b == N:
        B[a] = True
for s in S:
    if B[s]:
        print('POSSIBLE')
        sys.exit()
print('IMPOSSIBLE')
