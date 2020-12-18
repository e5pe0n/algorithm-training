N = int(input())
AB = [list(map(int, input().split())) for _ in range(N)]
res = 0
for a, b in AB[::-1]:
    res += (b - (a + res) % b) % b
print(res)
