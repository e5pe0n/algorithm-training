def naive_string_matcher(T: str, P: str):
    n = len(T)
    m = len(P)

    for i in range(n - m + 1):
        matched = True
        for j in range(m):
            if P[j] != T[i + j]:
                matched = False
                break
        if matched:
            print('pattern occurs with s = %d' % i)


T = "abcabaabcabac"
P = "abaa"

naive_string_matcher(T, P)
