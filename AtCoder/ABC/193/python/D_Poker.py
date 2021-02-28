from collections import Counter


def f(S):
    C = Counter(S)
    res = 0
    for i in range(1, 10):
        res += i * (10 ** C[str(i)])
    return res


K = int(input())
S = input()
T = input()

cards = Counter({str(i): K for i in range(1, 10)})
for i in range(4):
    cards[S[i]] -= 1
    cards[T[i]] -= 1


cnt = 0
t = 0
for i in range(1, 10):
    for j in range(1, 10):
        c = cards.copy()
        c[str(i)] -= 1
        c[str(j)] -= 1
        if c[str(i)] >= 0 and c[str(j)] >= 0:
            tS = f(S[:-1] + str(i))
            tT = f(T[:-1] + str(j))
            if tS > tT:
                cnt += cards[str(i)] * (cards[str(j)] - int(i == j))
            t += cards[str(i)] * (cards[str(j)] - int(i == j))
print(f"{cnt / t:.6f}")
