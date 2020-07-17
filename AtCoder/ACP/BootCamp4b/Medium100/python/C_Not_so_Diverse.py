import sys
N, K = list(map(int, input().split()))
A = list(map(int, input().split()))
if N == K:
    print(0)
    sys.exit()
_A = [0] * N
for a in A:
    _A[a - 1] += 1
_A.sort()
print(sum(_A) - sum(_A[N-K:]))
