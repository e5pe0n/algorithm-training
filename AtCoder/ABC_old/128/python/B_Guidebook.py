N = int(input())
T = [input().split() for _ in range(N)]
T = [(i, t[0], int(t[1])) for i, t in enumerate(T, 1)]

T.sort(key=lambda x: (x[1], -x[2]))
for t in T:
    print(t[0])
