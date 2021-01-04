N = int(input())
S = input()
w = len(list(filter(lambda x: x == '.', S)))
res = w
b = 0
for i in range(N):
    if S[i] == '#':
        b += 1
    else:
        w -= 1
    res = min(res, b + w)
print(res)
