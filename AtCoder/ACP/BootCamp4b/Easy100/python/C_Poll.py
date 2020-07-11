from collections import Counter
N = int(input())
C = Counter()
for i in range(N):
    C[input()] += 1
n = C.most_common(1)[0][1]
c = [k for k, v in C.items() if v == n]
c.sort()
for _c in c:
    print(_c)
