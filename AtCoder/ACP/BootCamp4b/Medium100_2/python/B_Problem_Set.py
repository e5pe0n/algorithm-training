from collections import Counter


N = int(input())
D = Counter(list(map(int, input().split())))
M = int(input())
T = Counter(list(map(int, input().split())))


for k, v in T.most_common():
    if v > D[k]:
        print("NO")
        exit()
print("YES")
