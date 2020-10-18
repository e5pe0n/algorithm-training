N, K = [int(x) for x in input().split()]
S = input()

ans = 0
for i in range(N - 1):
    ans += int(S[i + 1] == S[i])

left = 0
right = 0
cc_L = 0
cc_R = 0
while right < N:
    while right < N and S[right] == 'L':
        right += 1
    if right > left:
        cc_L += 1
    left = right
    while right < N and S[right] == 'R':
        right += 1
    if right > left:
        cc_R += 1
    left = right

if cc_L == cc_R:
    if K >= cc_L:
        ans += 2 * (cc_L - 1) + 1
    else:
        ans += 2 * K
else:
    ans += 2 * min(K, cc_L, cc_R)
ans = min(ans, N - 1)
print(ans)
