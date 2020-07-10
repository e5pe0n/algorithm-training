N = int(input())
T, A = list(map(int, input().split()))
H = list(map(int, input().split()))
t = 1_000_000
res = 0
for i in range(N):
    _t = abs(A - (T - H[i] * 0.006))
    if _t < t:
        res = i
        t = _t
print(res + 1)
