N = int(input())
A = [int(input()) for _ in range(N)]
if all(list(map(lambda x: x % 2 == 0, A))):
    print("second")
else:
    print("first")
