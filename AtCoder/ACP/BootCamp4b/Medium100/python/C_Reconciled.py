INF = 1_000_000_007
N, M = list(map(int, input().split()))
if abs(N - M) > 1:
    print(0)
else:
    a = 1
    for i in range(2, N + 1):
        a *= i
    b = 1
    for i in range(2, M + 1):
        b *= i
    print((a * b * (1 + int(N == M))) % INF)
