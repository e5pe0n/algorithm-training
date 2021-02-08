N = int(input())
S = input()
T = input()
cnt = 0
res1, res2 = 0, 0
for i in range(N):
    if T[i] == '1':
        res2 += i
        cnt += 1
    if S[i] == '1':
        if cnt > 0:
            res1 += i
            cnt -= 1
        else:
            res2 += i
            cnt += 1
if cnt > 0:
    print(-1)
else:
    print(res1 - res2)
