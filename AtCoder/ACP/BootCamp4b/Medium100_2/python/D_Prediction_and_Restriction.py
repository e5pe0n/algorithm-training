N, K = map(int, input().split())
X = list(map(int, input().split()))
T = input()
idx = {'r': 0, 's': 1, 'p': 2}

T = list(map(lambda x: idx[x], T))
res = 0
for i in range(N):
    me = (T[i] + 2) % 3
    if i - K < 0 or T[i - K] != me:
        res += X[me]
        T[i] = me
    else:
        T[i] = 4
print(res)
