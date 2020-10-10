N, M = [int(x) for x in input().split()]
p = M // N
ans = p
for _p in range(p, 0, -1):
    q = M % _p
    if q % _p == 0:
        ans = _p
        break
print(ans)
