N, M = map(int, input().split())
D = [[False] * N for _ in range(N)]
for _ in range(M):
    A, B = map(int, input().split())
    A -= 1
    B -= 1
    D[A][B] = True
    D[B][A] = True
for i in range(N):
    st = set()
    for j in range(N):
        if i == j:
            continue
        if not D[i][j]:
            continue
        for k in range(N):
            if k == i or k == j:
                continue
            if D[j][k] and not D[k][i]:
                st.add(k)
    print(len(st))
