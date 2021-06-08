import random

S = set()
while len(S) < 30:
    S.add(int(random.uniform(1, 100)))

S = list(S)
random.shuffle(S)
A = S[:20]
B = S[20:]


res = float('inf')
for a in A:
    for b in B:
        if res > abs(a - b):
            res = abs(a - b)
            p = (a, b)
print(' '.join(list(map(str, A))))
print(' '.join(list(map(str, B))))
print(res, p)
