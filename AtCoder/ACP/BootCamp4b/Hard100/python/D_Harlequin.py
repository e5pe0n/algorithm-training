N = int(input())
A = [int(input()) for _ in range(N)]
print("second" if all(list(map(lambda x: x % 2 == 0, A))) else "first")
