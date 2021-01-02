N = int(input())
G = [[] for _ in range(N)]
E = [None] * (N - 1)
for i in range(N - 1):
    a, b = map(lambda x: int(x) - 1, input().split())
    G[a].append(b)
    G[b].append(a)
    E[i] = (a, b)
stack = [0]
depth = [-1] * N
depth[0] = 0
while len(stack) > 0:
    u = stack.pop()
    for v in G[u]:
        if depth[v] < 0:
            depth[v] = depth[u] + 1
            stack.append(v)
s = [0] * N
Q = int(input())
for _ in range(Q):
    t, e, x = map(int, input().split())
    e -= 1
    a, b = E[e]
    if depth[a] > depth[b]:
        a, b = b, a
        t ^= 3
    if t == 1:
        s[0] += x
        s[b] -= x
    else:
        s[b] += x
stack = [0]
while len(stack) > 0:
    u = stack.pop()
    for v in G[u]:
        if depth[u] < depth[v]:
            s[v] += s[u]
            stack.append(v)
print('\n'.join(list(map(str, s))))
