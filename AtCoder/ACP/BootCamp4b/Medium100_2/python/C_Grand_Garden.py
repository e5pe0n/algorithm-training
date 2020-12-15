N = int(input())
H = list(map(int, input().split()))

h = max(H)
res = 0
if h == 0:
    print(res)
    exit()
while True:
    i = 0
    f = False
    while i < N:
        while i < N and H[i] == h:
            H[i] -= 1
            i += 1
            f = True
        res += int(f)
        f = False
        i += 1
    h -= 1
    if h == 0:
        print(res)
        exit()
