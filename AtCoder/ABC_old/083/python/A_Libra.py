I = input().split()
A, B, C, D = [int(i) for i in I]

if A + B > C + D:
    print('Left')
elif A + B < C + D:
    print('Right')
else:
    print('Balanced')
