class El:
    def __init__(self, id):
        self.id = id
        self.p = None
        self.rank = 0

    def __str__(self):
        return f'el{self.id}: p={self.p.id}, rank={self.rank}'


def make_set(x: El):
    x.p = x
    x.rank = 0


def union(x: El, y: El):
    link(find_set(x), find_set(y))


def link(x: El, y: El):
    if x is y:
        return
    if x.rank > y.rank:
        y.p = x
    else:
        x.p = y
        if x.rank == y.rank:
            y.rank += 1


def find_set(x: El) -> El:
    if x.p == x:
        return x
    else:
        x.p = find_set(x.p)
        return x.p


el1 = El(1)
el2 = El(2)
el3 = El(3)
el4 = El(4)
el5 = El(5)

els = [el1, el2, el3, el4, el5]
for el in els:
    make_set(el)

for el in els:
    print(el)
print()

union(el1, el2)
union(el3, el4)
union(el1, el3)
union(el4, el5)

for el in els:
    print(el)
