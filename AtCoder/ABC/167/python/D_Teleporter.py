N, K = map(int, input().split())
A = list(map(lambda x: int(x) - 1, input().split()))


al = []
cycle = []
od = {}
x = 0
for i in range(K + 1):
    if x in od:
        for j in range(od[x], i):
            cycle.append(al[j])
        break
    od[x] = len(al)
    al.append(x)
    x = A[x]
n = len(al)
if K == n - 1:
    print(al[K] + 1)
    exit()

K -= n
freq = len(cycle)
q = K % freq
print(cycle[q] + 1)
