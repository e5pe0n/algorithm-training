from time import perf_counter

N = [10**3, 10**4, 10**5, 10**6]
for n in N:
    mean = 0
    for _ in range(100):
        m = 0
        for _ in range(10):
            start = perf_counter()
            lst = []
            for i in range(n):
                lst.append('a')
            s = ''.join(lst)
            end = perf_counter()
            m += end - start
        mean += m / 10
    mean /= 100
    print(f"n={n}: duration[s]={mean}")
