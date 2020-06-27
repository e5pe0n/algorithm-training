N = int(input())
A = input().split()
A = [int(a) for a in A]

D = {}

for a in A:
    D[a] = D.get(a, 0) + 1

cnt = 0
for k, v in D.items():
    if k < v:
        cnt += v - k
    elif v < k:
        cnt += v
print(cnt)
