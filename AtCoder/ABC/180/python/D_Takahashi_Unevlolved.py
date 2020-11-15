X, Y, A, B = map(int, input().split())

res = 0
while X * A <= X + B and X * A < Y:
    X *= A
    res += 1
res += (Y - 1 - X) // B
print(res)
