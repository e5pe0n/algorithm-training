N = int(input())
x = int(input())
y = int(input())
A = [x, y]
if x < y:
    x, y = y, x
for i in range(N - 2):
    a = int(input())
    A.append(a)
    if x <= a:
        y = x
        x = a
    elif y < a:
        y = a
if x == y:
    for i in range(N):
        print(x)
else:
    for a in A:
        if a == x:
            print(y)
        else:
            print(x)
