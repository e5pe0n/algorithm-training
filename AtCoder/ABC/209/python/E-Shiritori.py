from collections import deque
M = 52**3
cnt = [0] * M
G = [[] for _ in range(M)]
res = [-1] * M


def chr2int(c):
    if c.isupper():
        return ord(c) - ord('A')
    else:
        return ord(c) - ord('a') + 26


def str2int(s):
    return chr2int(s[0]) * 52**2 + chr2int(s[1]) * 52 + chr2int(s[2])


N = int(input())
E = []
for _ in range(N):
    s = input()
    u = str2int(s[:3])
    v = str2int(s[-3:])
    cnt[u] += 1
    G[v].append(u)
    E.append((u, v))


q = deque()
for i in range(M):
    if cnt[i] == 0:
        res[i] = 0
        q.append(i)
while q:
    u = q.popleft()
    for v in G[u]:
        if res[v] != -1:
            continue
        cnt[v] -= 1
        if res[u] == 0:
            res[v] = 1
            q.append(v)
        elif cnt[v] == 0:
            res[v] = 0
            q.append(v)

for i in range(N):
    r = res[E[i][1]]
    if r == -1:
        print("Draw")
    elif r == 0:
        print("Takahashi")
    else:
        print("Aoki")
