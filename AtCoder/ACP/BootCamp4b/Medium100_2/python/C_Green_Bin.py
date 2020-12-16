from collections import Counter
N = int(input())
S = Counter([str(sorted(input())) for _ in range(N)])

res = 0
for k, v in S.most_common():
    res += v * (v - 1) // 2
print(res)
