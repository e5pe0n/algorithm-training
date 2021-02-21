N = int(input())
lst = []
for _ in range(N):
    w = int(input())
    if lst:
        _lst = list(filter(lambda x: w <= x, lst))
        if _lst:
            lst.remove(min(_lst))
    lst.append(w)
print(len(lst))
