from itertools import permutations
U = "UNSOLVABLE"

S1 = list(input())
S2 = list(input())
S3 = list(input())

st = set(S1 + S2 + S3)
if len(st) > 10:
    print(U)
    exit()

s1 = [0] * len(S1)
s2 = [0] * len(S2)
s3 = [0] * len(S3)
for i, n in enumerate(st):
    for j in range(len(S1)):
        if S1[j] == n:
            s1[j] = i
    for j in range(len(S2)):
        if S2[j] == n:
            s2[j] = i
    for j in range(len(S3)):
        if S3[j] == n:
            s3[j] = i


for perm in permutations(range(10)):
    _N1 = list(map(lambda x: perm[x], s1))
    _N2 = list(map(lambda x: perm[x], s2))
    _N3 = list(map(lambda x: perm[x], s3))
    if _N1[0] == 0 or _N2[0] == 0 or _N3[0] == 0:
        continue
    N1, N2, N3 = 0, 0, 0
    for n in _N1:
        N1 = N1 * 10 + n
    for n in _N2:
        N2 = N2 * 10 + n
    for n in _N3:
        N3 = N3 * 10 + n
    if N1 + N2 == N3:
        print(N1)
        print(N2)
        print(N3)
        exit()
print(U)
