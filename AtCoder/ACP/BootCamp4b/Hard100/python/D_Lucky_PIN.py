MAX_V = 999


N = int(input())
S = input()

cnt = 0
for i in range(MAX_V + 1):
    i_str = f"{i:03d}"
    idx = 0
    for s in S:
        if s == i_str[idx]:
            idx += 1
            if idx >= len(i_str):
                break
    if idx == len(i_str):
        cnt += 1
print(cnt)
