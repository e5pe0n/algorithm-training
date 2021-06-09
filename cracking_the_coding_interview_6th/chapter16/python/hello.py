import random

N = 10
S = set()
while len(S) < N:
    S.add(random.uniform(1900, 2000))

S = sorted(list(S))
births = S[:5]
deads = S[5:]

random.shuffle(births)
random.shuffle(deads)

for b, d in zip(births, deads):
    print(b, d)
