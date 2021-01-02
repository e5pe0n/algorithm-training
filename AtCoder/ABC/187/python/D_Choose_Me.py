N = int(input())
AB = sorted([list(map(int, input().split())) for _ in range(N)], key=lambda x: 2 * x[0] + x[1])
sum_A = sum(list(map(lambda x: x[0], AB)))
res = 0
for a, b in AB[::-1]:
    sum_A -= 2 * a + b
    res += 1
    if sum_A < 0:
        break
print(res)
