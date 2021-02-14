S = input()
V = []
i = 0
cnt = 0
while i < len(S):
    if S[i:i+2] == "25":
        cnt += 1
        i += 2
    else:
        if cnt > 0:
            V.append(cnt)
        cnt = 0
        i += 1
if cnt > 0:
    V.append(cnt)
res = 0
for v in V:
    res += v * (v + 1) // 2
print(res)
