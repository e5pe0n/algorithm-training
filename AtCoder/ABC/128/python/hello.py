T = [(1, 'c', 1.5), (2, 'b', 2.3), (3, 'b', 0.5)]
T.sort(key=lambda x: (x[1], -x[2]))
print(T)
