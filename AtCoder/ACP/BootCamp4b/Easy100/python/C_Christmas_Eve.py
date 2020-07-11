MAX_H = 1_000_000_000
N, K = list(map(int, input().split()))
H = [int(input()) for _ in range(N)]
H.sort()
res = MAX_H
for i in range(N - K + 1):
    _h = min(H[i:i+K])
    h = max(H[i:i+K])
    res = min(res, h - _h)
    if res == 0:
        break
print(res)
