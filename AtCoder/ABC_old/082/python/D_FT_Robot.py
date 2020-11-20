MAX_SIZE = 16_001
OFFSET = 8_000

X = [[False for _ in range(MAX_SIZE)] for _ in range(2)]
Y = [[False for _ in range(MAX_SIZE)] for _ in range(2)]

s = input()
x, y = [int(i) for i in input().split()]
N = len(s)

i = 0
d = 0
j = 0
while i < N and s[i] == 'F':
    d += 1
    i += 1
X[j][d + OFFSET] = True

i += 1
d = 0
while i < N and s[i] == 'F':
    d += 1
    i += 1
i += 1
Y[j][d + OFFSET] = True
Y[j][-d + OFFSET] = True

j += 1
while i < N:
    d = 0
    while i < N and s[i] == 'F':
        d += 1
        i += 1
    for k in range(2 * N + 1):
        if k - d >= 0 and k + d <= 2 * N:
            X[j % 2][k - N + OFFSET] = X[(j - 1) % 2][k - N + OFFSET -
                                                      d] or X[(j - 1) % 2][k - N + OFFSET + d]
        elif k - d >= 0:
            X[j % 2][k - N + OFFSET] = X[(j - 1) % 2][k - N + OFFSET - d]
        elif k + d <= 2 * N:
            X[j % 2][k - N + OFFSET] = X[(j - 1) % 2][k - N + OFFSET + d]
    i += 1
    d = 0
    while i < N and s[i] == 'F':
        d += 1
        i += 1
    for k in range(2 * N + 1):
        if k - d >= 0 and k + d <= 2 * N:
            Y[j % 2][k - N + OFFSET] = Y[(j - 1) % 2][k - N + OFFSET -
                                                      d] or Y[(j - 1) % 2][k - N + OFFSET + d]
        elif k - d >= 0:
            Y[j % 2][k] = Y[(j - 1) % 2][k - N + OFFSET - d]
        elif k + d <= 2 * N:
            Y[j % 2][k] = Y[(j - 1) % 2][k - N + OFFSET + d]
    i += 1
    j += 1

if (X[(j - 1) % 2][x + OFFSET] and Y[(j - 1) % 2][y + OFFSET]):
    print('Yes')
else:
    print('No')
