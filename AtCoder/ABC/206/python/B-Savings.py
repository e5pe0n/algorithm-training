N = int(input())
MAX_N = 10**9
for i in range(1, MAX_N):
    t = i * (i + 1)
    if N * 2 <= t:
        print(i)
        exit()
