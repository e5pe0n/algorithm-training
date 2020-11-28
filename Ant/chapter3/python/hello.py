from bisect import bisect_left

s = set([(20, 1), (30, 2), (40, 3)])
print(bisect_left(s, (20, 1)))
