from heapq import heapify, heappop, heappush


N, W = map(int, input().split())
V = [list(map(int, input().split())) for _ in range(N)]
V.sort()

q = []
heapify(q)
i = 0
p = 0
while i < N:
    if len(q) == 0 or V[i][0] < q[0][0]:
        p += V[i][2]
        if p > W:
            print('No')
            exit()
        heappush(q, [V[i][1], V[i][0], V[i][2]])
        i += 1
    else:
        v = heappop(q)
        p -= v[2]
print('Yes')
