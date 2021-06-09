import random

N = 200
lst = []
while len(lst) < N:
    lst.append(int(random.uniform(1900, 2000)))

for i in range(0, N, 2):
    print(min(lst[i], lst[i + 1]), max(lst[i], lst[i + 1]))
