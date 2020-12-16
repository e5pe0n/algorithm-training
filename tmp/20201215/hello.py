from time import perf_counter

N = [10**3, 10**4, 10**5, 10**6]
for n in N:
    mean = 0
    for _ in range(100):
        m = 0
        for _ in range(10):
            start = perf_counter()
            s = ""
            for i in range(n):
                s += "a"
            end = perf_counter()
            m += end - start
        mean += m / 10
    mean /= 100
    print(f"n={n}: duration[s]={mean}")

# n=1000: duration[s]=0.00014572650028276253
# n=10000: duration[s]=0.0015365726002783036
# n=100000: duration[s]=0.01521512579993578
# n=1000000: duration[s]=0.15250789780003834
