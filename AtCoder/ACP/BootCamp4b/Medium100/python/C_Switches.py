N, M = list(map(int, input().split()))
V = [list(map(lambda x: int(x) - 1, input().split()))[1:] for _ in range(M)]
P = list(map(int, input().split()))
res = 0
for i in range(1 << N):
    B = format(i, f'0{N}b')[::-1]
    flg = True
    for j in range(M):
        cnt = 0
        for s in V[j]:
            if B[s] == '1':
                cnt += 1
        if cnt % 2 != P[j]:
            flg = False
    res += int(flg)
print(res)
