H, W = [int(i) for i in input().split()]
S = [input() for _ in range(H)]
for j in range(W + 2):
    print('#', end='')
print()
for i in range(H):
    print('#%s#' % S[i])
for j in range(W + 2):
    print('#', end='')
print()
