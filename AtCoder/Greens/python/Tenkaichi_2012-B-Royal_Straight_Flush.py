S = input()
D = {
    'S': [],
    'H': [],
    'D': [],
    'C': []
}
N = ["10", "J", "Q", "K", "A"]


def show(m, res):
    _res = list(filter(lambda x: not (x[0] == m and x[1:] in N), res))
    if _res:
        print(''.join(_res))
    else:
        print(0)


res = []
m, n = "", ""
for s in S:
    if s in D:
        if n in N:
            D[m].append(m + n)
            if len(D[m]) >= 5:
                show(m, res)
                exit()
        if m:
            res.append(m + n)
        m = s
        n = ""
    else:
        n += s
res.append(m + n)
show(m, res)
