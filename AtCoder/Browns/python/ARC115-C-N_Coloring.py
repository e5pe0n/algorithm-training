N = int(input())

A = [0] * (N + 1)
A[1] = 1


def divisors(n):
    res = []
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            res.append(i)
            if n // i not in (i, n):
                res.append(n // i)
    return res


for i in range(2, N + 1):
    divs = divisors(i)
    st = set()
    for d in divs:
        st.add(A[d])
    A[i] = len(st) + 1
print(' '.join(list(map(str, A[1:]))))
