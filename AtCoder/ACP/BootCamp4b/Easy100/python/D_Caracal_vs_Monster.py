import sys
H = int(input())
if H == 1:
    print(1)
    sys.exit()
cnt = 1
i = 1
H //= 2
while H > 0:
    i <<= 1
    cnt += i
    H //= 2
print(cnt)
