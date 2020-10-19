N = int(input())
F = [list(map(int, input().split())) for _ in range(N)]
P = [list(map(int, input().split())) for _ in range(N)]

ans = float("-inf")
for i in range(1, 1 << 10):
    B = format(i, "010b")
    t = 0
    for j in range(N):
        cc = 0
        for k in range(10):
            if B[k] == '1' and F[j][k]:
                cc += 1
        t += P[j][cc]
    ans = max(ans, t)
print(ans)
