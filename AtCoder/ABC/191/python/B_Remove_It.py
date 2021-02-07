N, X = map(int, input().split())
A = list(map(int, input().split()))
A = list(filter(lambda x: x != X, A))
print(' '.join(list(map(str, A))))
