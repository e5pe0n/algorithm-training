N, K = map(int, input().split())
A = list(map(int, input().split()))

sm = [0] * (N + 1)
for i in range(N):
    sm[i + 1] = sm[i] + A[i]

left = 0
right = 1
res = 0
while left < N and right <= N:
    while right <= N and sm[right] - sm[left] < K:
        right += 1
    if right > N:
        break
    res += N - right + 1
    left += 1
    while left < N and sm[right] - sm[left] >= K:
        res += N - right + 1
        left += 1
print(res)
