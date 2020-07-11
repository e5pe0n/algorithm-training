A, B, C, X, Y = list(map(int, input().split()))
if X == Y:
    print(min(A + B, 2 * C) * X)
elif X < Y:
    print(min(A + B, 2 * C) * X + min(B, 2 * C) * (Y - X))
else:
    print(min(A + B, 2 * C) * Y + min(A, 2 * C) * (X - Y))
