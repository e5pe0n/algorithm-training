N = int(input())
S, T = input().split()
res = ''.join(map(lambda x: x[0] + x[1], zip(S, T)))
print(res)
