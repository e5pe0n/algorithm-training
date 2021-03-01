N, T = map(int, input().split())
AB = [list(map(int, input().split())) for _ in range(N)]
sumA = sum(list(map(lambda x: x[0], AB)))
sumB = sum(list(map(lambda x: x[1], AB)))
if sumB > T:
    print(-1)
    exit()
sumA -= T
D = sorted(list(map(lambda x: x[0] - x[1], AB)), reverse=True)
i = 0
while sumA > 0:
    sumA -= D[i]
    i += 1
print(i)
