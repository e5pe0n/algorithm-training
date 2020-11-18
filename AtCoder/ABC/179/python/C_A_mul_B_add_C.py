N = int(input())
cnt = 0
for a in range(1, N):
    t = a
    b = 1
    while t * b < N:
        cnt += 1
        b += 1
print(cnt)
