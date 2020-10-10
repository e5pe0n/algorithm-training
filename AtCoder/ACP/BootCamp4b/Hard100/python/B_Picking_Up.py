from collections import Counter
import sys


N = int(input())
C = [[int(x) for x in input().split()] for _ in range(N)]

if N == 1:
    print(1)
    sys.exit()


M = Counter()
for i in range(N):
    for j in range(N):
        if i != j:
            dx = C[i][0] - C[j][0]
            dy = C[i][1] - C[j][1]
            M[dx, dy] += 1
cnt = M.most_common(1)[0][1]
print(N - cnt)
