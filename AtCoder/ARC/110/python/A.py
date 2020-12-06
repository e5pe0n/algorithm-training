N = int(input())
res = 1
for i in range(2, N + 1):
    res *= i
print(res + 1)

for i in range(2, N + 1):
    print((res + 1) % i)
