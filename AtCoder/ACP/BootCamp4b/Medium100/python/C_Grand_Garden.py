import sys
N = int(input())
H = list(map(int, input().split()))
res = 0
while True:
    i = 0
    cnt = 0
    while i < N:
        while i < N and H[i] <= 0:
            i += 1
        if i >= N:
            break
        while i < N and H[i] > 0:
            H[i] -= 1
            i += 1
        cnt += 1
    if cnt == 0:
        print(res)
        sys.exit()
    else:
        res += cnt
