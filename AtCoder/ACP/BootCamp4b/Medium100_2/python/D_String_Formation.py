S = input()
Q = int(input())
f = True
front = []
back = []
for _ in range(Q):
    query = input().split()
    if len(query) == 1:
        f = not f
    else:
        _, F, C = query
        if (F == '1' and f) or (F == '2' and not f):
            front.append(C)
        else:
            back.append(C)
if f:
    res = ''.join(front)[::-1] + S + ''.join(back)
else:
    res = ''.join(back)[::-1] + S[::-1] + ''.join(front)
print(res)
