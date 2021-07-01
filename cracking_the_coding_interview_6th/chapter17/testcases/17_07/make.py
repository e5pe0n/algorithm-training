from collections import defaultdict
import random


with open("words02.txt") as f:
    words = list(map(lambda x: x.strip(), list(f)))

d = defaultdict(list)
for w in words:
    d[w[0]].append(w)

res = []
for k, v in d.items():
    if len(v) < 2:
        continue
    random.shuffle(v)
    for s in v[1:]:
        if int(random.uniform(0, 2)):
            res.append(f"{v[0]} {s}\n")
        else:
            res.append(f"{s} {v[0]}\n")
with open("synonyms02.txt", "w") as f:
    f.write("".join(res))

# lst = [(w, int(random.uniform(0, 100))) for w in words]
# s = list(map(lambda x: f"{x[0]} {x[1]}\n", lst))
# with open("names02.txt", 'w') as f:
#     f.write(''.join(s))
