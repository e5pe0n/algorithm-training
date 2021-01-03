N, H = map(int, input().split())
AB = [list(map(int, input().split())) for _ in range(N)]

max_a = max(list(map(lambda x: x[0], AB)))
AB.sort(key=lambda x: x[1])
res = 0
for a, b in AB[::-1]:
    if H <= 0 or b < max_a:
        break
    H -= b
    res += 1
if H > 0:
    res += (H + max_a - 1) // max_a
print(res)
