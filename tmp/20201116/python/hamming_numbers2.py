from time import perf_counter


N = [50, 1000, 10000, 1000000, 1000000000]
F = [2, 3, 5]

for n in N:
    start = perf_counter()
    H = [1]
    right = 1
    for f in F:
        for left in range(right):
            x = f
            while H[left] * x <= n:
                H.append(H[left] * x)
                x *= f
        right = len(H)
    end = perf_counter()
    print(f"{n}:{len(H)} ({end - start}[s])")

# 50:24 (1.4299992471933365e-05[s])
# 1000:86 (3.920006565749645e-05[s])
# 10000:175 (8.530006743967533e-05[s])
# 1000000:507 (0.00018580001778900623[s])
# 1000000000:1530 (0.0005379000212997198[s])
