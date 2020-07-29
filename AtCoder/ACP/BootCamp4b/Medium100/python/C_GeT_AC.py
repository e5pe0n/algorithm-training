import bisect
N, Q = list(map(int, input().split()))
S = input()
R = [0] * Q
V = []
Vp = V.append
for i in range(N - 1):
    if S[i:i+2] == 'AC':
        Vp(i)
for i in range(Q):
    l, r = list(map(int, input().split()))
    if len(V) > 0:
        l -= 1
        r -= 1
        low = bisect.bisect_left(V, l)
        up = bisect.bisect_right(V, r - 1) - 1
        R[i] = up - low + 1
    else:
        R[i] = 0
print('\n'.join(list(map(str, R))))
