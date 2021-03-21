N = int(input())
A = list(map(int, input().split()))

ps = sorted(list(filter(lambda x: x >= 0, A)))
ng = sorted(list(filter(lambda x: x < 0, A)), reverse=True)
res = []
if len(ng) == 0:
    for i in range(len(ps) - 2):
        res.append((ps[i], ps[i + 1]))
        ps[i + 1] = ps[i] - ps[i + 1]
    res.append((ps[-1], ps[-2]))
    M = ps[-1] - ps[-2]
elif len(ps) == 0:
    for i in range(1, len(ng)):
        res.append((ng[0], ng[i]))
        ng[0] -= ng[i]
    M = ng[0]
else:
    for i in range(len(ps) - 1):
        res.append((ng[0], ps[i]))
        ng[0] -= ps[i]
    for i in range(len(ng)):
        res.append((ps[-1], ng[i]))
        ps[-1] -= ng[i]
    M = ps[-1]
print(M)
print("\n".join(list(map(lambda x: f"{x[0]} {x[1]}", res))))
