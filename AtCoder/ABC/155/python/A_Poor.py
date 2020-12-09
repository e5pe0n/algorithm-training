A, B, C = sorted(list(map(int, input().split())))
if (A == B and B != C) or (A != B and B == C):
    print("Yes")
else:
    print("No")
