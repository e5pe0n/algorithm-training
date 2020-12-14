R, G, B, N = map(int, input().split())

NR = N // R
NG = N // G
res = 0
for i in range(NR + 1):
    for j in range(NG + 1):
        n = N - R * i - G * j
        if n >= 0 and n % B == 0:
            res += 1
print(res)
