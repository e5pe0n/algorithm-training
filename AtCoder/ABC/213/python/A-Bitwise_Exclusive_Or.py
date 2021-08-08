A, B = map(int, input().split())
for c in range(256):
    if A ^ c == B:
        print(c)
