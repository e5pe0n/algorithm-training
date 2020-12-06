from heapq import heapify, heappop, heappush


X, Y, A, B, C = map(int, input().split())
P = list(map(int, input().split()))
Q = list(map(int, input().split()))
R = list(map(int, input().split()))
P.sort()
Q.sort()
pq, qq = P[A - X:], Q[B - Y:]
heapify(pq)
heapify(qq)
for r in R:
    p = pq[0]
    q = qq[0]
    if p < q:
        if p < r:
            heappop(pq)
            heappush(pq, r)
    else:
        if q < r:
            heappop(qq)
            heappush(qq, r)
res = sum(pq) + sum(qq)
print(res)
