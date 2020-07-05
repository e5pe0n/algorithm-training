A, B = list(map(int, input().split()))
a = 1
cnt = 0
while a < B:
    a -= 1
    a += A
    cnt += 1
print(cnt)
