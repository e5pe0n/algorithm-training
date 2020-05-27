class Edge:
    def __init__(self, u):
        self.u = u


E = [Edge(i) for i in range(3)]

_E = []
for e in E:
    _E.append(e)

_E[0].u = 100

print(E[0].u)
print(_E[0].u)
