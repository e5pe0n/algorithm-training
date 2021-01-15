N, K = map(int, input().split())
S = input()
left, right = 0, 0
while right < N:
    f = False
    while right < N and S[right] == '0':
        right += 1
        f = True
    while right < N and S[right] == '1':
        right += 1
    K -= int(f)
    if K <= 0:
        break
res = right - left
while right < N:
    while right < N and S[right] == '0':
        right += 1
    while right < N and S[right] == '1':
        right += 1
    while left < N and S[left] == '1':
        left += 1
    while left < N and S[left] == '0':
        left += 1
    res = max(res, right - left)
print(res)
