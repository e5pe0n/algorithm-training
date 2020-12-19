N = int(input())


res = 0
for i in range(1, N + 1):
    n = i
    s10 = []
    while n > 0:
        s10.append(n % 10)
        n //= 10
    n = i
    s8 = []
    while n > 0:
        s8.append(n % 8)
        n //= 8
    if 7 not in s10 and 7 not in s8:
        res += 1
print(res)
