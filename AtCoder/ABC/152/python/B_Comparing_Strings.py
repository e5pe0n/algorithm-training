a, b = input().split()
if a > b:
    a, b = b, a
if a <= b:
    print(a * int(b))
else:
    print(b * int(a))
