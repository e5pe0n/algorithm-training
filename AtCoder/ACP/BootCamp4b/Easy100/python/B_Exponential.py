import math
X = int(input())
res = 1
for i in range(2, int(math.sqrt(X)) + 1):
    j = 2
    while i ** j <= X:
        j += 1
    res = max(res, i ** (j - 1))
print(res)
