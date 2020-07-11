import sys
s = input()
for i in range(len(s) - 1):
    if s[i] == 'A':
        left = i
        break
for i in range(len(s) - 1, -1, -1):
    if s[i] == 'Z':
        print(i - left + 1)
        sys.exit()
