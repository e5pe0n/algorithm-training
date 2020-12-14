H, W = map(int, input().split())
A = [list(input()) for _ in range(H)]

st_h = set()
st_w = set()
for i in range(H):
    f = True
    for j in range(W):
        if A[i][j] == '#':
            f = False
            break
    if f:
        st_h.add(i)
for j in range(W):
    f = True
    for i in range(H):
        if A[i][j] == '#':
            f = False
            break
    if f:
        st_w.add(j)
for i in range(H):
    if i not in st_h:
        print(''.join(['' if j in st_w else A[i][j] for j in range(W)]))
