N, M, T = map(int, input().split())
AB = [list(map(int, input().split())) for _ in range(M)]
A = [ab[0] for ab in AB]
B = [ab[1] for ab in AB]

t = N
for i in range(M):
    if i == 0:
        t -= A[i]
    else:
        t -= A[i] - B[i - 1]
    if t <= 0:
        print("No")
        exit()
    t = min(N, t + B[i] - A[i])
t -= T - B[-1]
if t > 0:
    print("Yes")
else:
    print("No")
