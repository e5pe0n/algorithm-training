from collections import Counter
N = int(input())
C = Counter(list(map(lambda x: int(x) % 200, input().split())))
res = 0
for v in C.values():
    res += v * (v - 1) // 2
print(res)
