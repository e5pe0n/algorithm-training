N = int(input())
TS = []
for i in range(N):
    s, t = input().split()
    TS.append((int(t), s))
TS.sort()
print(TS[-2][1])
