from functools import partial


p = partial(print, end="")
sx, sy, tx, ty = [int(x) for x in input().split()]
p("L")
for i in range(ty - sy + 1):
    p("U")
for i in range(tx - sx + 1):
    p("R")
for i in range(ty - sy + 1):
    p("D")
for i in range(tx - sx):
    p("L")
for i in range(ty - sy):
    p("U")
for i in range(tx - sx + 1):
    p("R")
for i in range(ty - sy + 1):
    p("D")
for i in range(tx - sx + 1):
    p("L")
print("U")
