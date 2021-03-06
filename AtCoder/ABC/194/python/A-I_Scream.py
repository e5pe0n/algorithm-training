A, B = map(int, input().split())
A += B
if 15 <= A and 8 <= B:
    print(1)
elif 10 <= A and 3 <= B:
    print(2)
elif 3 <= A:
    print(3)
else:
    print(4)
