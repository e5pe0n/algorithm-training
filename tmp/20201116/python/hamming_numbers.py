from time import perf_counter


n = int(input())

start = perf_counter()
res = 1
for i in range(2, n + 1):
    t = i
    for j in [2, 3, 5]:
        while t % j == 0:
            t //= j
    if t == 1:
        res += 1
print(res)
end = perf_counter()
print(f"duration[s]={end - start}")
