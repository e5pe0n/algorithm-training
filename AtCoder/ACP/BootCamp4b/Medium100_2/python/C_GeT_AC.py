N, Q = map(int, input().split())
S = input()
LR = list(map(lambda x: int(x) - 1, input().split()) for _ in range(Q))
sm = [0] * (N + 1)
for i in range(N):
    sm[i + 1] = sm[i] + int(i - 1 >= 0 and S[i - 1] == 'A' and S[i] == 'C')
for L, R in LR:
    print(sm[R + 1] - sm[L + 1])
