N, M, C = list(map(int, input().split()))
B = list(map(int, input().split()))
cnt = 0
for i in range(N):
    t = 0
    for i, a in enumerate(input().split()):
        t += B[i] * int(a)
    if t + C > 0:
        cnt += 1
print(cnt)
