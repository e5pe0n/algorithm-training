from collections import Counter
N = int(input())
V = list(map(int, input().split()))
C1 = Counter(V[::2])
C2 = Counter(V[1::2])
V1 = C1.most_common()
V2 = C2.most_common()
if len(V1) == 1 and len(V2) == 1 and V1[0][0] == V2[0][0]:
    print(N // 2)
    exit()
res = N
if V1[0][0] == V2[0][0]:
    if len(V2) >= 2:
        res = min(res, N // 2 - V1[0][1] + N // 2 - V2[1][1])
    if len(V1) >= 2:
        res = min(res, N // 2 - V1[1][1] + N // 2 - V2[0][1])
else:
    res = N // 2 - V1[0][1] + N // 2 - V2[0][1]
print(res)
