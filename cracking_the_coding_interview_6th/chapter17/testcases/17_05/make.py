import random


alphs = list(map(lambda x: chr(x + ord('a')), range(26)))
nums = list(range(10))

n = 50
res = []
alphnum = alphs + nums
for i in range(n):
    x = int(random.uniform(0, len(alphnum)))
    res.append(str(alphnum[x]))
print("".join(res))
