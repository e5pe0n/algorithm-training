INF = float('inf')
N = int(input())
A = list(map(int, input().split()))

sm = [0] * (N + 2)
for i in range(N):
    sm[i + 1] = sm[i] + A[i]
sm[N + 1] = INF
sm.sort()
cnt = 0
res = 0
for i in range(N + 1):
    if sm[i + 1] == sm[i]:
        cnt += 1
    else:
        res += cnt * (cnt + 1) // 2
        cnt = 0
print(res)
