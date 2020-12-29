from functools import partial
sx, sy, tx, ty = map(int, input().split())
p = partial(print, end="")
for y in range(ty - sy):
    p('U')
for x in range(tx + 1 - sx):
    p('R')
for y in range(ty + 1 - sy):
    p('D')
for x in range(tx + 1 - sx):
    p('L')
p("UL")
for y in range(ty + 1 - sy):
    p('U')
for x in range(tx + 1 - sx):
    p('R')
for y in range(ty + 1 - sy):
    p('D')
for x in range(tx - sx):
    p('L')
print()
