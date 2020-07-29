import math
x = int(input())
print((x // 11) * 2 + int(math.ceil((x % 11) / 6)))
