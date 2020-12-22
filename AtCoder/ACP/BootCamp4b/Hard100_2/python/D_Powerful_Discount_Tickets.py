from heapq import heapify, heappop, heappush
N, M = map(int, input().split())
A = list(map(lambda x: -int(x), input().split()))

heapify(A)
for _ in range(M):
    a = heappop(A)
    a *= -1
    a >>= 1
    heappush(A, -a)
res = sum(A)
print(-res)
