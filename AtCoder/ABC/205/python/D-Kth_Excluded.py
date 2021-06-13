from bisect import bisect_left

MAX_A = 10**18

N, Q = map(int, input().split())
A = [0] + list(map(int, input().split())) + [MAX_A]
S = [0] * (N + 1)
for i in range(1, N + 1):
    S[i] = S[i - 1] + A[i] - A[i - 1] - 1
for _ in range(Q):
    K = int(input())
    idx = bisect_left(S, K)
    print(K + idx - 1)
