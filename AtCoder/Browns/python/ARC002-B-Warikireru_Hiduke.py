days = [
    [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31],
    [0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31],
]

Y, M, D = map(int, input().split('/'))
while True:
    d = days[0]
    if Y % 4 == 0 and Y % 100 != 0 or Y % 400 == 0:
        d = days[1]
    while M <= 12:
        while D <= d[M]:
            if Y % M == 0 and (Y // M) % D == 0:
                print(f"{Y:04d}/{M:02d}/{D:02d}")
                exit()
            D += 1
        M += 1
        D = 1
    Y += 1
    M = D = 1
