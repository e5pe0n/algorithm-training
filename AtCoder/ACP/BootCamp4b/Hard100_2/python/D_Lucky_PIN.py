N = int(input())
S = input()

res = 0
for i in range(1000):
    n = f"{i:03d}"
    idx = 0
    for s in S:
        if s == n[idx]:
            idx += 1
            if idx >= 3:
                break
    if idx >= 3:
        res += 1
print(res)
