N = int(input())
A = [int(x) for x in input().split()]

C = [0] * max(A)
for a in A:
    C[a - 1] += 1

cnt = 0
even_cnt = 0
for c in C:
    if c > 0:
        cnt += 1
        if c % 2 == 0:
            even_cnt += 1
ans = cnt - int(even_cnt % 2 != 0)
print(ans)
