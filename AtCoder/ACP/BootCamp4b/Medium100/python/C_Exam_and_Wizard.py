import sys
N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
if sum(A) < sum(B):
    print(-1)
    sys.exit()
V = []
Vp = V.append
_V = []
_Vp = _V.append
for i in range(N):
    d = A[i] - B[i]
    if d > 0:
        Vp(d)
    elif d < 0:
        _Vp(-d)
if len(_V) == 0:
    print(0)
    sys.exit()
V.sort()
_V.sort()
i = len(V) - 1
_i = len(_V) - 1
t = 0
res = 0
while _i >= 0:
    if t < 0:
        t += V[i]
        i -= 1
        res += 1
    else:
        t -= _V[_i]
        _i -= 1
        res += 1
print(res + int(t < 0))
