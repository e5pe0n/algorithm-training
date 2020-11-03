from bisect import bisect_left


def ns(f):
    return next(f).strip()


def loop(i, f, g):
    i = 0
    while f(i):
        yield i
        i = g(i)


with open("../testset/subsequence/test2.txt", 'r') as f:
    n, S = map(int, ns(f).split())
    a = list(map(int, ns(f).split()))

s = [0]
for _a in a:
    s.append(s[-1] + _a)

if s[n] < S:
    print(0)
    exit()

ans = n
for i in loop(0, lambda x: s[x] + S <= s[n], lambda x: x + 1):
    j = bisect_left(s, s[i] + S, i)
    ans = min(ans, j - i)
print(ans)
