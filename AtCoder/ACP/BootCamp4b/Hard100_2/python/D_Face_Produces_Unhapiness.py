N, K = map(int, input().split())
S = list(input())
if S[0] == 'R':
    S = list(map(lambda x: 'R' if x == 'L' else 'L', S))
i = 0
while i < N and K:
    f = False
    while i < N and S[i] == 'R' and K:
        S[i] = 'L'
        i += 1
        f = True
    K -= int(f)
    while i < N and S[i] == 'L':
        i += 1
res = 0
for i in range(N - 1):
    if (S[i + 1] == 'R' and S[i] == 'R') or (S[i + 1] == 'L' and S[i] == 'L'):
        res += 1
print(res)
