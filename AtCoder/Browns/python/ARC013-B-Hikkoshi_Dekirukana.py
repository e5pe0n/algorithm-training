C = int(input())
V = [sorted(list(map(int, input().split()))) for _ in range(C)]
max_N = max(list(map(lambda x: x[0], V)))
max_M = max(list(map(lambda x: x[1], V)))
max_L = max(list(map(lambda x: x[2], V)))
print(max_N * max_M * max_L)
