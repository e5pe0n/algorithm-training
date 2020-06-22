import math


d = 10
q = 11


def rabin_karp_matcher(T: str, P: str):
    n = len(T)
    m = len(P)

    h = int(math.pow(d, m - 1))
    t = 0
    p = 0

    for i in range(m):
        t = (d * t + int(T[i])) % q
        p = (d * p + int(P[i])) % q

    for i in range(n - m + 1):
        if p == t:
            matched = True
            for j in range(m):
                if P[j] != T[j]:
                    matched = False
                    break
            if matched:
                print('pattern occurs with s = %d\n', i)
        if i < n - m:
            t = (d * (t - int(T[i]) * h) + T[i + m]) % q
