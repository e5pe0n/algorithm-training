from collections import Counter
n = int(input())
V = list(map(int, input().split()))
_n = n // 2
C0 = Counter()
C1 = Counter()
for i in range(n):
    if i % 2 == 0:
        C0[V[i]] += 1
    else:
        C1[V[i]] += 1
C0 = C0.most_common()
C1 = C1.most_common()
if C0[0][0] == C1[0][0]:
    if len(C0) == 1 and len(C1) == 1:
        print(_n)
    elif C0[0][1] == C1[0][1]:
        if C0[1][1] <= C1[1][1]:
            print(abs(C0[0][1] - _n) + abs(C1[1][1] - _n))
        else:
            print(abs(C0[1][1] - _n) + abs(C1[0][1] - _n))
    else:
        if C0[0][1] < C1[0][1]:
            print(abs(C0[1][1] - _n) + abs(C1[0][1] - _n))
        else:
            print(abs(C0[0][1] - _n) + abs(C1[1][1] - _n))
else:
    print(abs(C0[0][1] - _n) + abs(C1[0][1] - _n))
