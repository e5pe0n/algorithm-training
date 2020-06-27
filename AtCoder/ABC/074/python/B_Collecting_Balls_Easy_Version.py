N = int(input())
K = int(input())
X = input().split()
cnt = 0
for x in X:
    cnt += min(int(x), K - int(x))
print(cnt * 2)
