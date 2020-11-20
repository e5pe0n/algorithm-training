from collections import Counter


H, W, M = map(int, input().split())
s = set()
ch = Counter()
cw = Counter()
for _ in range(M):
    h, w = map(lambda x: int(x) - 1, input().split())
    s.add((h, w))
    ch[h] += 1
    cw[w] += 1

max_ch = ch.most_common(1)[0][1]
hs = []
for h, c in ch.most_common():
    if c == max_ch:
        hs.append(h)
max_cw = cw.most_common(1)[0][1]
ws = []
for w, c in cw.most_common():
    if c == max_cw:
        ws.append(w)
for h in hs:
    for w in ws:
        if not (h, w) in s:
            print(max_ch + max_cw)
            exit()
print(max_ch + max_cw - 1)
