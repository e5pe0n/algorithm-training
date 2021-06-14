import re

PAT = re.compile(r"([a-zA-Z]+)")

S = set()
with open("source.txt") as f:
    for line in f:
        line = line.strip()
        for m in PAT.finditer(line):
            S.add(m.group().lower())

S = list(S)
with open("words.txt", 'w') as f:
    f.writelines(list(map(lambda x: x + '\n', S)))
