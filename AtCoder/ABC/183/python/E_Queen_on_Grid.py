MOD = int(1e9) + 7


H, W = map(int, input().split())
S = [input() for _ in range(H)]
d = [0] * W
col = [0] * W
dia = [0] * (H + W - 1)

for i in range(H):
    t = 0
    for j in range(W):
        k = H - 1 - i + j
        if i == 0 and j == 0:
            d[0] = 1
            t = 1
            col[j] = 1
            dia[k] = 1
        elif S[i][j] == '#' or (t == 0 and col[j] == 0 and dia[k] == 0):
            d[j] = 0
            t = 0
            col[j] = 0
            dia[k] = 0
        else:
            d[j] = (t + col[j] + dia[k]) % MOD
            t = (t + d[j]) % MOD
            col[j] = (col[j] + d[j]) % MOD
            dia[k] = (dia[k] + d[j]) % MOD
print(d[W - 1])
