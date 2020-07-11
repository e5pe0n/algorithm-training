S = input()
n = False
e = False
s = False
w = False
for _s in S:
    if _s == 'N':
        n = True
    if _s == 'E':
        e = True
    if _s == 'S':
        s = True
    if _s == 'W':
        w = True
if (n and s and e and w) or (n and s and not e and not w) or (not n and not s and e and w):
    print('Yes')
else:
    print('No')
