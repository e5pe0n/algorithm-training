A = int(input())
MAX_K = 10**4
for k in range(10, MAX_K + 1):
    sk = str(k)
    N = len(sk)
    t = 0
    for i, s in enumerate(sk[::-1]):
        t += int(s) * (k ** i)
    if t == A:
        print(k)
        exit()
print(-1)
