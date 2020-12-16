N = int(input())
V = sorted([list(map(int, input().split())) for _ in range(N)], key=lambda x: x[1])

t = 0
for v in V:
    t += v[0]
    if t > v[1]:
        print("No")
        exit()
print("Yes")
