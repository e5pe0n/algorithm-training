S = input()
N = len(S)
C = [0] * N
i = 0
while i < N:
    cnt = 0
    while i < N and S[i] == 'R':
        i += 1
        cnt += 1
    C[i - 1] += cnt // 2 + int(cnt % 2 != 0)
    C[i] += cnt // 2
    while i < N and S[i] == 'L':
        i += 1
i = N - 1
while i >= 0:
    cnt = 0
    while i >= 0 and S[i] == 'L':
        i -= 1
        cnt += 1
    C[i + 1] += cnt // 2 + int(cnt % 2 != 0)
    C[i] += cnt // 2
    while i >= 0 and S[i] == 'R':
        i -= 1
for c in C:
    print(c)
