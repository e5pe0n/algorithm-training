H, W, N = map(int, input().split())
AB = [list(map(int, input().split())) for _ in range(N)]
A = list(map(lambda x: x[0], AB))
B = list(map(lambda x: x[1], AB))
_A = sorted(list(set(A)))
_B = sorted(list(set(B)))
da = {a: i + 1 for i, a in enumerate(_A)}
db = {b: i + 1 for i, b in enumerate(_B)}
for a, b in AB:
    print(f"{da[a]} {db[b]}")
