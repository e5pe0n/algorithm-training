O = input()
E = input()
if len(O) == len(E):
    for s in zip(O, E):
        print(s[0] + s[1], end='')
    print()
else:
    print(O[0], end='')
    for s in zip(E, O[1:]):
        print(s[0] + s[1], end='')
    print()
