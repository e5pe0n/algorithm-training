S = list(input())
K = int(input())
N = len(S)
left = 1
while left < N and S[0] == S[left]:
    left += 1
right = 0
while N - 1 - right and S[0] == S[N - 1 - right]:
    right += 1
S += S
cnt = 0
for i in range(len(S) - 1):
    if S[i + 1] == S[i]:
        S[i + 1] = 'A'
        cnt += 1
if left + right < N and left % 2 != 0 and right % 2 != 0:
    print(max(0, (cnt + 1) * (K // 2) + ((cnt + 1) // 2) * int(K % 2 != 0) - 1))
else:
    print(cnt * (K // 2) + (cnt // 2) * int(K % 2 != 0))
