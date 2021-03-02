from bisect import bisect_left
MAX_S = 10**6
N = int(input())
S = [0] * (MAX_S + 2)
for _ in range(N):
    s = int(input())
    S[s] += 1
N -= S[0]
S[0] = 0
for i in range(MAX_S + 1, 0, -1):
    S[i - 1] += S[i]
for i in range(MAX_S + 2):
    S[i] = N - S[i]
Q = int(input())
for _ in range(Q):
    k = int(input())
    idx = bisect_left(S, N - k)
    print(idx)
