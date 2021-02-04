A = int(input())
B = int(input())
fs = [True] * 3
fs[A - 1] = False
fs[B - 1] = False
for i, f in enumerate(fs, 1):
    if f:
        print(i)
        exit()
