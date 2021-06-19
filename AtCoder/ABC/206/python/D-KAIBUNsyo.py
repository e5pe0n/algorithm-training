MAX_A = 2*(10**5)
N = int(input())
A = list(map(int, input().split()))

par = list(range(MAX_A + 1))
rnk = [0] * (MAX_A + 1)


def find(x):
    global par, rnk
    if x == par[x]:
        return par[x]
    par[x] = find(par[x])
    return par[x]


def unite(x, y):
    x = find(x)
    y = find(y)
    if x == y:
        return
    if rnk[x] < rnk[y]:
        par[x] = y
    else:
        par[y] = x
        if rnk[x] == rnk[y]:
            rnk[x] += 1


def same(x, y):
    return find(x) == find(y)


res = 0
left = 0
right = N - 1
while left < right:
    if not same(A[left], A[right]):
        unite(A[left], A[right])
        res += 1
    left += 1
    right -= 1
print(res)
