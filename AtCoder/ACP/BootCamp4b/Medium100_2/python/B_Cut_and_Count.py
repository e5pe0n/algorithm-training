N = int(input())
S = input()

res = 0
for md in range(1, N - 1):
    used = {}
    for i in range(md):
        used[S[i]] = True
    cnt = 0
    for i in range(md, N):
        if S[i] in used:
            cnt += 1
            del used[S[i]]
    res = max(res, cnt)
print(res)
