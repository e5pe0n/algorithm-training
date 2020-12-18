from collections import Counter
N = int(input())
C = Counter(list(map(int, input().split())))

if len(C) == 1 and C[0] == N:
    print("Yes")
    exit()
if N % 3 != 0:
    print("No")
    exit()
if len(C) == 2 and (N - C[0]) % 2 == 0 and (N - C[0]) <= 2 * C[0]:
    print("Yes")
    exit()
if len(C) == 3:
    V = []
    for k, v in C.most_common():
        if v != N // 3:
            print("No")
            exit()
        V.append(k)
    for i in range(3):
        if (V[i] ^ V[(i + 2) % 3]) != V[(i + 1) % 3]:
            print("No")
            exit()
    print("Yes")
    exit()
print("No")
