lst = [0, 1, 4, 7, 10, 11, 12, 16, 17, 19, 20, 24, 28, 30, 35]
res = []
for i in range(len(lst) - 1):
    res.append((lst[i + 1] - lst[i]) * 15)
with open("02.txt", "w") as f:
    f.write(f"{len(res)}\n{' '.join(list(map(str, res)))}")
