N = int(input())
if N == 0:
    print(0)
    exit()
res = ""
while N != 0:
    res = str(abs(N % 2)) + res
    N = N // -2 + max(0, (N // -2) * -2 - N)
print(res)
