X = input()
s = 0
cnt = 0
for x in X:
    if x == 'S':
        s += 1
    else:
        if s > 0:
            s -= 1
            cnt += 1
res = len(X) - 2 * cnt
print(res)
