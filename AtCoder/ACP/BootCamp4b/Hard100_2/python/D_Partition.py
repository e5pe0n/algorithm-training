N, M = map(int, input().split())
p = M // N
while p > 0:
    q = M % p
    if q % p == 0:
        res = p
        break
    p -= 1
print(res)
