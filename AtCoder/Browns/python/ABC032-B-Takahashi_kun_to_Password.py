S = input()
K = int(input())
res = set()
for i in range(len(S) - K + 1):
    res.add(S[i:i+K])
print(len(res))
