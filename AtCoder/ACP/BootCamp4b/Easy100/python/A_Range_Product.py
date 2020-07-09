a, b = list(map(int, input().split()))
if a > b:
    a, b = b, a
if 0 < a or (b < 0 and (b - a) % 2 == 1):
    print('Positive')
elif a <= 0 and 0 <= b:
    print('Zero')
else:
    print('Negative')
