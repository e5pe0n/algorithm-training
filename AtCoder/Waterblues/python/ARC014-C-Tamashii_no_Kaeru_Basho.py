N = int(input())
S = input()
r, g, b = 0, 0, 0
for c in S:
    if c == 'R':
        r += 1
    if c == 'G':
        g += 1
    if c == 'B':
        b += 1
res = (r % 2) + (g % 2) + (b % 2)
print(res)
