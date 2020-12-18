a, b, c = map(int, input().split())
x = c - a - b
if x > 0 and 4 * a * b < x * x:
    print("Yes")
else:
    print("No")
