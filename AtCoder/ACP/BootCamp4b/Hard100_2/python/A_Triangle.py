MAX_X = 10**9
S = int(input())
X1, Y1 = 0, 0
X2, Y2 = MAX_X, 1
Y3 = (S + MAX_X - 1) // MAX_X
X3 = MAX_X * Y3 - S
print(X1, Y1, X2, Y2, X3, Y3)
