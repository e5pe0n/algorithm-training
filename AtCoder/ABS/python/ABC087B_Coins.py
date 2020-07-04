A = int(input())
B = int(input())
C = int(input())
X = int(input())

NA = min(int(X / 500), A)
NB = min(int(X / 100), B)
NC = min(int(X / 50), C)
cnt = 0
for i in range(NA + 1):
    for j in range(NB + 1):
        for k in range(NC + 1):
            if 500 * i + 100 * j + 50 * k == X:
                cnt += 1
print(cnt)
