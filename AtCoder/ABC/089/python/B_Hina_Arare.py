import sys

N = int(input())
S = input()

for s in S:
    if s == 'Y':
        print('Four')
        sys.exit()
print('Three')
