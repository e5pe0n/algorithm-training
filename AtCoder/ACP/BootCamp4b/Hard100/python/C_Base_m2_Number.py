N = int(input())

if N == 0:
    print(0)
    exit()

ans = ""
while N != 0:
    ans = str(abs(N % 2)) + ans
    N = -1 * (N // 2)
print(ans)
