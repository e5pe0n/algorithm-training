def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


A, B, C, D = list(map(int, input().split()))
Bc = B // C
Bd = B // D
Ac = (A - 1) // C
Ad = (A - 1) // D
lcm = C * D // gcd(C, D)
Blcm = B // lcm
Alcm = (A - 1) // lcm
print((B - A + 1) - ((Bc - Ac) + (Bd - Ad) - (Blcm - Alcm)))
