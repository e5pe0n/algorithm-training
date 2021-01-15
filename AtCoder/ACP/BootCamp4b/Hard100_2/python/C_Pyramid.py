N = int(input())
XYH = [list(map(int, input().split())) for _ in range(N)]
max_h = max(list(map(lambda x: x[2], XYH)))
for cx in range(101):
    for cy in range(101):
        for H in range(max_h, max_h + 201):
            f = True
            for x, y, h in XYH:
                if h != max(H - abs(x - cx) - abs(y - cy), 0):
                    f = False
                    break
            if f:
                print(cx, cy, H)
                exit()
