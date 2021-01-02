A, B = input().split()
print(max(sum([int(x) for x in A]), sum([int(x) for x in B])))
