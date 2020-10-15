N, X = [int(x) for x in input().split()]

P = [2 ** (i + 1) - 1 for i in range(0, N + 1)]
L = [P[i] * 2 - 1 for i in range(0, N + 1)]

layer_cnt = 0
p_cnt = 0
while N >= 0:
    if N == 0:
        p_cnt += 1
        break
    if layer_cnt + 1 == X:
        break
    if layer_cnt + (L[N] + 1) // 2 == X:
        p_cnt += P[N - 1] + 1
        break
    if layer_cnt + L[N] == X:
        p_cnt += P[N]
        break
    if X < layer_cnt + (L[N] + 1) // 2:
        layer_cnt += 1
    else:
        layer_cnt += L[N - 1] + 2
        p_cnt += P[N - 1] + 1
    N -= 1
print(p_cnt)
