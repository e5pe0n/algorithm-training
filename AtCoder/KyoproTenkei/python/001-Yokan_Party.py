INF = 10**10
N, L = map(int, input().split())
K = int(input())
A = [0] + list(map(int, input().split())) + [L]
D = []
for i in range(N + 1):
    D.append(A[i + 1] - A[i])
lb = 0
ub = INF
while ub - lb > 1:
    mid = (lb + ub) // 2
    k = 0
    t = 0
    for d in D:
        t += d
        if t >= mid:
            k += 1
            t = 0
    if k >= K + 1:
        lb = mid
    else:
        ub = mid
print(lb)
