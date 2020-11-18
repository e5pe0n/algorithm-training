N = int(input())
D = [list(map(int, input().split())) for _ in range(N)]
cnt = 0
for d1, d2 in D:
    if d1 == d2:
        cnt += 1
        if cnt >= 3:
            print("Yes")
            exit()
    else:
        cnt = 0
print("No")
