from collections import Counter


MOD = 2019


S = input()
d = 1
sm = [0] * (len(S) + 1)
for i, s in enumerate(S[::-1]):
    sm[i + 1] += (sm[i] + int(s) * d) % MOD
    d = (d * 10) % MOD
cnt = Counter()
for s in sm:
    cnt[s] += 1
res = 0
for c in cnt.values():
    res += c * (c - 1) // 2
print(res)
