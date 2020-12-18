INF = float('inf')
N = int(input())
S = [input() for _ in range(N)]
cnt2 = [INF] * 26
for s in S:
    cnt1 = [0] * 26
    for c in s:
        cnt1[ord(c) - ord('a')] += 1
    cnt2 = [min(c1, c2) for c1, c2 in zip(cnt1, cnt2)]
res = ''.join([chr(i + ord('a')) * cnt2[i] for i in range(26)])
print(res)
