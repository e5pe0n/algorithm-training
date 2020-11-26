N = int(input())

res = 0
for i in range(1, N + 1):
    res += (N // i) * (N // i + 1) * i // 2
print(res)
