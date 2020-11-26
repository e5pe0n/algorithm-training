from collections import Counter


N = int(input())
S = [input() for _ in range(N)]
cnt = Counter()
for s in S:
    if s == "AC":
        cnt[s] += 1
    if s == "WA":
        cnt[s] += 1
    if s == "TLE":
        cnt[s] += 1
    if s == "RE":
        cnt[s] += 1
print(f"AC x {cnt['AC']}")
print(f"WA x {cnt['WA']}")
print(f"TLE x {cnt['TLE']}")
print(f"RE x {cnt['RE']}")
