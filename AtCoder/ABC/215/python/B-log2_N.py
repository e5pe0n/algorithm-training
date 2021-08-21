N = int(input())
k = 0
while N >= 2:
    k += 1
    N >>= 1
print(k)
