from heapq import heapify, heappop, heappush
X, Y, A, B, C = map(int, input().split())
P = sorted(list(map(int, input().split())), reverse=True)[:X]
Q = sorted(list(map(int, input().split())), reverse=True)[:Y]
R = list(map(int, input().split()))

q = P + Q
heapify(q)
for r in R:
    p = heappop(q)
    if p < r:
        heappush(q, r)
    else:
        heappush(q, p)
print(sum(q))
