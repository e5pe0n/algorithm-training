S = [input() for _ in range(4)]
d = {"H": 0, "2B": 0, "3B": 0, "HR": 0}
for s in S:
    if s in d:
        d[s] += 1
if all(v == 1 for v in d.values()):
    print("Yes")
else:
    print("No")
