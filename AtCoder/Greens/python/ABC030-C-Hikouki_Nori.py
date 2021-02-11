N, M = map(int, input().split())
X, Y = map(int, input().split())
A = sorted(list(map(lambda x: (int(x) + X, int(x)), input().split())))
B = sorted(list(map(lambda x: (int(x) + Y, int(x)), input().split())))
idx_a = 0
idx_b = 0
n = 0
t = 0
while True:
    if n % 2 == 0:
        if idx_a >= N:
            break
        if t <= A[idx_a][1]:
            t = A[idx_a][0]
            n += 1
        idx_a += 1
    else:
        if idx_b >= M:
            break
        if t <= B[idx_b][1]:
            t = B[idx_b][0]
            n += 1
        idx_b += 1
print(n // 2)
