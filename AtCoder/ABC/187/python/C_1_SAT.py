from collections import defaultdict
N = int(input())
S = [input() for _ in range(N)]

A = defaultdict(set)
for s in S:
    if s[0] == '!':
        A[s[1:]].add(s)
    else:
        A[s].add(s)
for k, v in A.items():
    if len(v) >= 2:
        print(k)
        exit()
print('satisfiable')
