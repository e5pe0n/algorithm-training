N = int(input())
S = input()

w = len([s for s in S if s == '.'])
ans = w
b = 0
for s in S:
    if s == '#':
        b += 1
    else:
        w -= 1
    ans = min(ans, b + w)
print(ans)
