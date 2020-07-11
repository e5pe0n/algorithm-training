N, M = map(int, input().split())
A = [False] * N
B = [0] * N
cnt = 0
for i in range(M):
    p, S = input().split()
    if not A[int(p) - 1]:
        if S == 'AC':
            cnt += 1
            A[int(p) - 1] = True
        else:
            B[int(p) - 1] += 1
_cnt = 0
for i in range(N):
    if A[i]:
        _cnt += B[i]
print(cnt, _cnt)
