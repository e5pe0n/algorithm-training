S = input()
Q = int(input())
f = False
front, back = [], []
for _ in range(Q):
    query = input().split()
    if len(query) == 1:
        f = not f
    else:
        F, C = query[1:]
        if F == "1":
            if f:
                back.append(C)
            else:
                front.append(C)
        else:
            if f:
                front.append(C)
            else:
                back.append(C)
if f:
    res = "".join(back[::-1]) + S[::-1] + "".join(front)
else:
    res = "".join(front[::-1]) + S + "".join(back)
print(res)
