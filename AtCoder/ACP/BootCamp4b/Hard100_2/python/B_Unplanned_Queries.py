from collections import Counter
N, M = map(int, input().split())
AB = [list(map(int, input().split())) for _ in range(M)]
C = Counter()
for a, b in AB:
    C[a] += 1
    C[b] += 1
if all(list(map(lambda x: x % 2 == 0, C.values()))):
    print("YES")
else:
    print("NO")
