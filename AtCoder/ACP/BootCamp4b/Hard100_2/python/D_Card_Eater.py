from collections import Counter
N = int(input())
C = Counter(list(map(int, input().split())))

cnt = 0
for v in C.values():
    if v % 2 == 0:
        cnt += 1
res = len(C) - int(cnt % 2 != 0)
print(res)
