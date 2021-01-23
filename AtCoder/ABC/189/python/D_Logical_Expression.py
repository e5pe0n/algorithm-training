N = int(input())
S = [input() for _ in range(N)]

res = 1
for i, s in enumerate(S):
    if s == "OR":
        res = res + 2 ** (i + 1)
print(res)
