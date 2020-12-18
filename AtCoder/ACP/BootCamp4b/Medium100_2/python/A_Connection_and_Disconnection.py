S = input()
K = int(input())
N = len(S)
res = 0
cnt = 0
for i in range(N - 1):
    if S[i] == S[i + 1]:
        cnt += 1
    else:
        res += (cnt + 1) // 2
        cnt = 0
res += (cnt + 1) // 2
if K == 1:
    print(res)
    exit()
same = cnt + 1 == N
S += S
cnt = 0
sm = 0
for i in range(N * 2 - 1):
    if S[i] == S[i + 1]:
        cnt += 1
    else:
        sm += (cnt + 1) // 2
        cnt = 0
sm += (cnt + 1) // 2
if same:
    res = sm * (K // 2) + res * (K % 2)
else:
    res = (sm - res) * (K - 1) + res
print(res)
