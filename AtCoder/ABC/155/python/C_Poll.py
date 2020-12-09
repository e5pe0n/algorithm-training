from collections import Counter


N = int(input())
cnt = Counter()
for _ in range(N):
    cnt[input()] += 1
res = []
max_cnt = cnt.most_common()[0][1]
for s, v in cnt.most_common():
    if v != max_cnt:
        break
    res.append(s)
res.sort()
print("\n".join(res))
