N = int(input())


st = set()
for i in range(2, int(N ** 0.5) + 1):
    n = i * i
    while n <= N:
        st.add(n)
        n *= i

print(N - len(st))
