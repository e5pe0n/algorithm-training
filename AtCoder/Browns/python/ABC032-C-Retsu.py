N, K = map(int, input().split())
S = [int(input()) for _ in range(N)]
if 0 in S:
    print(N)
    exit()
if K == 0 and 0 not in S:
    print(0)
    exit()
left, right = 0, 0
t = 1
res = 0
while right < N:
    while right < N and t * S[right] <= K:
        t *= S[right]
        right += 1
    res = max(res, right - left)
    if right - left == 0:
        break
    if right >= N:
        break
    while left < N and t * S[right] > K:
        t //= S[left]
        left += 1
print(res)
