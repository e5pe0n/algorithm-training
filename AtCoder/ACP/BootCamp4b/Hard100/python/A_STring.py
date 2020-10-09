X = input()
s = 0
cnt = 0
for x in X:
    if x == 'S':
        s += 1
    elif s > 0:
        cnt += 2
        s -= 1
print(len(X) - cnt)
