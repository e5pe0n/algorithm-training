from math import ceil
A, B = map(int, input().split())
min_a = int(ceil(A * 100 / 8))
max_a = int(ceil((A + 1) * 100 / 8)) - 1
min_b = B * 10
max_b = (B + 1) * 10 - 1
for a in range(min_a, max_a + 1):
    for b in range(min_b, max_b + 1):
        if a == b:
            print(a)
            exit()
print(-1)
