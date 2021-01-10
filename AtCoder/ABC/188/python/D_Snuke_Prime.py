from collections import defaultdict
N, C = map(int, input().split())
ABC = [list(map(int, input().split())) for _ in range(N)]
A = defaultdict(list)
B = defaultdict(list)
for i, (a, b, c) in enumerate(ABC):
    A[a].append(i)
    B[b + 1].append(i)
events = set(list(A.keys()) + list(B.keys()))
events = sorted(list(events))
prv = 0
t = 0
res = 0
for e in events:
    res += min(C, t) * (e - prv)
    for v in A[e]:
        t += ABC[v][2]
    for v in B[e]:
        t -= ABC[v][2]
    prv = e
print(res)
