from collections import deque


S = input()
q = deque()
for s in S:
    if s in ('0', '1'):
        q.append(s)
    else:
        if len(q) > 0:
            q.pop()
res = ''.join(q)
print(res)
