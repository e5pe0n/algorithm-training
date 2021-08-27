from collections import Counter
N, K = map(int, input().split())
A = list(map(int, input().split()))
left, right = 0, 0
C = Counter()
res = 0
while right < N:
    while right < N and (len(C) < K or A[right] in C):
        C[A[right]] += 1
        right += 1
    res = max(res, right - left)
    while len(C) == K:
        C[A[left]] -= 1
        if C[A[left]] == 0:
            del C[A[left]]
        left += 1
print(res)
