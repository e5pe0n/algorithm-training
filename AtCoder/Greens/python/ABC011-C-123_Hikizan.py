N = int(input())
NG = [int(input()) for _ in range(3)]
if N in NG:
    print("NO")
    exit()

cnt = 100
while N > 0 and cnt > 0:
    cnt -= 1
    for i in range(3, 0, -1):
        f = True
        n = N - i
        for ng in NG:
            if ng == n:
                f = False
                break
        if f:
            N = n
            break
if N > 0:
    print("NO")
else:
    print("YES")
