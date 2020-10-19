N, x = map(int, input().split())
A = list(map(int, input().split()))
D = [A[i + 1] + A[i] for i in range(N - 1)]
ans = 0
for i in range(len(D) - 1):
    if D[i] - x > 0:
        d = D[i] - x
        ans += d
        D[i] -= d
        D[i + 1] -= min(d, A[i + 1])
if D[-1] - x > 0:
    d = D[-1] - x
    ans += d
    D[-1] -= d
print(ans)
