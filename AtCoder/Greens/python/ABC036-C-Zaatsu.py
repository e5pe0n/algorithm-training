N = int(input())
A = [int(input()) for _ in range(N)]
d = {v: i for i, v in enumerate(list(set(sorted(A))))}
print('\n'.join(list(map(lambda x: str(d[x]), A))))
