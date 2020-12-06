INF = float('inf')


H, W, K = map(int, input().split())
S = [list(input()) for _ in range(H)]
res = INF
for h in range(1 << (H - 1)):
    c = len(list(filter(lambda i: h >> i & 1, range(H))))
    sm = [0] * (c + 1)
    div = 0
    for j in range(W):
        t = 0
        idx = 0
        cnt = [0] * (c + 1)
        for i in range(H):
            if S[i][j] == '1':
                t += 1
            if h >> i & 1:
                if t > K:
                    div = INF
                    break
                cnt[idx] += t
                idx += 1
                t = 0
        if t > K or div == INF:
            div = INF
            break
        cnt[idx] += t
        if any([x + y > K for x, y in zip(sm, cnt)]):
            div += 1
            sm = cnt.copy()
        else:
            sm = [x + y for x, y in zip(sm, cnt)]
    res = min(res, div + c)
print(res)
