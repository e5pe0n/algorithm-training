t = 0
for i in range(1, 314159 + 1):
    S = str(i)
    cnt = 0
    for s in S:
        if s != '0':
            cnt += 1
    if cnt == 3:
        print(S)
        t += 1
print(t)
