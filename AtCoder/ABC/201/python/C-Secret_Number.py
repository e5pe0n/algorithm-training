S = list(input())
must = 0
for c in S:
    if c == 'o':
        must += 1
res = 0
for i in range(10000):
    s = f"{i:04d}"
    ok = True
    must_set = set()
    for c in s:
        if S[int(c)] == 'x':
            ok = False
            break
        if S[int(c)] == 'o':
            must_set.add(int(c))
    if ok and len(must_set) == must:
        res += 1
print(res)
