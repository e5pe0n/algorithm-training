import sys
s = int(input())
A = [False] * 1_000_001
cnt = 1
A[s] = True


def f(n):
    if n % 2 == 0:
        return n // 2
    else:
        return 3 * n + 1


while True:
    s = f(s)
    cnt += 1
    if A[s]:
        print(cnt)
        sys.exit()
    else:
        A[s] = True
