N = int(input())

if N == 0:
    print(0)
    exit()

res = ""
while N != 0:
    res = ("0" if N % 2 == 0 else "1") + res
    N = -1 * (N // 2)

print(res)
