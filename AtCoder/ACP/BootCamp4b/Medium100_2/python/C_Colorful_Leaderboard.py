N = int(input())
A = list(map(int, input().split()))

used = [False] * 8
cnt = 0
for a in A:
    if a >= 3200:
        cnt += 1
    else:
        used[a // 400] = True
min_res = len(list(filter(lambda x: x, used)))
max_res = min_res + cnt
min_res = max(min_res, 1)
print(min_res, max_res)
