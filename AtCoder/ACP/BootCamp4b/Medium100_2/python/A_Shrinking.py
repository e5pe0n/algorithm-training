S = input()
res = len(S)
for c in S:
    prv = S
    nxt = ""
    cnt = 0
    while True:
        if all(list(map(lambda x: x == c, prv))):
            break
        for i in range(len(prv) - 1):
            if prv[i] == c or prv[i + 1] == c:
                nxt += c
            else:
                nxt += prv[i]
        nxt, prv = prv, nxt
        nxt = ""
        cnt += 1
    res = min(res, cnt)
print(res)
