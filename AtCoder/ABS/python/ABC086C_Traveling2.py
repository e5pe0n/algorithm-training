import sys
N = int(input())
C = [[int(c) for c in input().split()] for _ in range(N)]

C = [[0, 0, 0]] + C
for i in range(N):
    dt = C[i + 1][0] - C[i][0]
    dx = abs(C[i + 1][1] - C[i][1])
    dy = abs(C[i + 1][2] - C[i][2])
    if not (dt >= dx + dy and (dt - dx - dy) % 2 == 0):
        print('No')
        sys.exit()
print('Yes')
