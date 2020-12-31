N = int(input())
CSF = [list(map(int, input().split())) for _ in range(N - 1)]
for i in range(N):
    t = 0
    for C, S, F in CSF[i:]:
        if t <= S:
            t = S + C
        else:
            t = S + ((t - S) + F - 1) // F * F + C
    print(t)
