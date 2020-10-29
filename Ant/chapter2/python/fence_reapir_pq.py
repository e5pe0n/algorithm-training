from heapq import heapify, heappop, heappush


def ns(f):
    return next(f).strip()


with open("../testset/fence_repair/test2.txt", 'r') as f:
    N = int(ns(f))
    L = list(map(int, ns(f).split()))


ans = 0
heapify(L)
while len(L) > 1:
    mi1 = heappop(L)
    mi2 = heappop(L)
    ans += mi1 + mi2
    heappush(L, mi1 + mi2)
print(ans)
