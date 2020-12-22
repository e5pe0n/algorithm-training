S = input()
N = len(S)
C = [0] * N
cnt = 0
for i in range(N):
    if S[i] == 'R':
        cnt += 1
    else:
        C[i] += cnt // 2
        if i - 1 >= 0:
            C[i - 1] += (cnt + 2 - 1) // 2
        cnt = 0
cnt = 0
for i in range(N - 1, -1, -1):
    if S[i] == 'L':
        cnt += 1
    else:
        C[i] += cnt // 2
        if i + 1 <= N - 1:
            C[i + 1] += (cnt + 2 - 1) // 2
        cnt = 0
print(' '.join(list(map(str, C))))
