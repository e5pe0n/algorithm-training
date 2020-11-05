from bisect import bisect, bisect_left, bisect_right

# 0  1  2  3  4  5  6  7  8  9  10 11 12 13 14
lst = [1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5]

print(f"bisect={bisect(lst, 4)}")
print(f"bisect_left={bisect_left(lst, 4)}")
print(f"bisect_right={bisect_right(lst, 4)}")
