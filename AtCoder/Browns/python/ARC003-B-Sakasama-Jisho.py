N = int(input())
S = [input() for _ in range(N)]
S.sort(key=lambda x: x[::-1])
print('\n'.join(S))
