x, y = map(int, input().split())

if x == y:
    print(x)
else:
    if x != 0 and y != 0:
        print(0)
    elif x != 1 and y != 1:
        print(1)
    else:
        print(2)
