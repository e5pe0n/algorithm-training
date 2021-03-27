S = input()
s = "set"
d = "dict"

if S == "{}":
    print(d)
    exit()

V = []
for c in S:
    if c == '{':
        V.append(c)
    if c == '}':
        V.pop()
    if c == ':' and len(V) == 1:
        print(d)
        exit()
print(s)
