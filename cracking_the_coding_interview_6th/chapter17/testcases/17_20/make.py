import random

fp = "05.txt"
n_rounds = 4
rounds = [10, 10, 10]
rngs = [(0, 20), (20, 40), (40, 100)]

arr = [[int(random.uniform(*rng))
        for i in range(r)] for rng, r in zip(rngs, rounds)]
arr_s = "\n".join(map(lambda x: ' '.join(map(str, x)), arr))
rounds_s = ' '.join(map(str, rounds))

arrs = []
meds = []
for a in arr:
    arrs += a
    arrs.sort()
    meds.append(arrs[(len(arrs) - 1) // 2])
    print(arrs, meds)
meds_s = ' '.join(map(str, meds))

with open(fp, 'w') as f:
    f.write(f"{n_rounds}\n{rounds_s}\n{arr_s}\n\nans: {meds_s}")
