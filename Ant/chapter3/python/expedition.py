from heapq import heapify, heappop, heappush


def ns(f):
    return next(f).strip()


with open("../testset/expedition/test1.txt", 'r') as f:
    N, L, P = map(int, ns(f).split())
    A = list(map(int, ns(f).split())) + [L]
    B = list(map(int, ns(f).split())) + [0]

N += 1
ans, pos, tank = 0, 0, P
q = []
heapify(q)
for i in range(N):
    d = A[i] - pos
    while tank - d < 0:
        if len(q) == 0:
            print("-1")
            exit()
        tank += -heappop(q)
        ans += 1
    tank -= d
    pos = A[i]
    heappush(q, -B[i])
print(ans)
