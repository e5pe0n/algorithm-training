a, b, c = list(map(int, input().split()))
t = c - a - b
if t > 0 and 4 * a * b < t * t:
    print('Yes')
else:
    print('No')
