N, K = map(int, input().split())
S = input()

nxts = [[0] * 26 for _ in range(N)] + [[N] * 26]
for i in range(N - 1, -1, -1):
    for j in range(26):
        if ord(S[i]) - ord('a') == j:
            nxts[i][j] = i
        else:
            nxts[i][j] = nxts[i + 1][j]


res = []
curr = 0
for i in range(K):
    for j in range(26):
        nxt = nxts[curr][j]
        remain = (N - nxt - 1) + (i + 1)
        if remain >= K:
            res.append(S[nxt])
            curr = nxt + 1
            break
print(''.join(res))
