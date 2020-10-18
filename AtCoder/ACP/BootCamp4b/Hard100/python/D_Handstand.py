N, K = list(map(int, input().split()))
S = input()

idx = 0
V = []
while idx < N:
    cc = 0
    while idx < N and S[idx] == '1':
        cc += 1
        idx += 1
    V.append(cc)
    cc = 0
    while idx < N and S[idx] == '0':
        cc += 1
        idx += 1
    if cc > 0:
        V.append(cc)
if S[-1] == '0':
    V.append(0)

N_V = len(V)
w = min(K * 2 + 1, N_V)
t = sum(V[:w])
ans = t
for i in range(2, N_V - w + 1, 2):
    t = t - V[i - 2] - V[i - 1] + V[i + w - 2] + V[i + w - 1]
    ans = max(ans, t)
print(ans)
