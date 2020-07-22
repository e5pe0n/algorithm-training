import sys
N = int(input())
V = [list(map(int, input().split())) for _ in range(N)]
V.sort(key=lambda x: x[1])
s = 0
for v in V:
    s += v[0]
    if s > v[1]:
        print('No')
        sys.exit()
print('Yes')
