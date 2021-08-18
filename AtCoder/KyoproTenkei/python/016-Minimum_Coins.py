MAX_RES = 9999
N = int(input())
A, B, C = sorted(map(int, input().split()))
res = MAX_RES
for i in range(min(MAX_RES, N // C) + 1):
    m1 = N - C * i
    for j in range(min(MAX_RES, m1 // B) + 1):
        m2 = m1 - B * j
        if m2 % A == 0:
            res = min(res, i + j + m2 // A)
print(res)
