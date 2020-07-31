import sys
N, K = list(map(int, input().split()))
V = [list(map(int, input().split())) for _ in range(N)]
V.sort()
cnt = 0
res = 0
for v in V:
    cnt += v[1]
    if cnt >= K:
        print(v[0])
        sys.exit()
