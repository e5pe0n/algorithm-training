import sys

w = input()
W = [0] * 26
for _w in w:
    W[ord(_w) - ord('a')] += 1
for _w in W:
    if _w % 2 != 0:
        print('No')
        sys.exit()
print('Yes')
