N = int(input())
A = sorted(list(map(int, input().split())))
B = sorted(list(map(int, input().split())))
C = sorted(list(map(int, input().split())))

AB = [0] * N
BC = [0] * N

j = N - 1
for c in C[::-1]:
    while j >= 0 and c <= B[j]:
        j -= 1
        if j >= 0:
            BC[j] = BC[j + 1]
    if j >= 0 and c > B[j]:
        BC[j] += 1
while j > 0:
    BC[j - 1] = BC[j]
    j -= 1

j = 0
for a in A:
    while j < N and a >= B[j]:
        j += 1
        if j < N:
            AB[j] = AB[j - 1]
    if j < N and a < B[j]:
        AB[j] += 1
while j < N - 1:
    AB[j + 1] = AB[j]
    j += 1

res = sum(list(map(lambda x: x[0] * x[1], zip(AB, BC))))
print(res)
