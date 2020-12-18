from collections import Counter
N, K = map(int, input().split())
AB = [list(map(int, input().split())) for _ in range(N)]
C = Counter()
for a, b in AB:
    C[a] += b
V = sorted(map(list, C.most_common()), key=lambda x: x[0])
cnt = 0
for k, v in V:
    cnt += v
    if cnt >= K:
        print(k)
        exit()
