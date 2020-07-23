import sys
Sa = input()
Sb = input()
Sc = input()
Na = len(Sa)
Nb = len(Sb)
Nc = len(Sc)
ia, ib, ic = 0, 0, 0
t = 'a'
while True:
    if t == 'a':
        while ia < Na and Sa[ia] == 'a':
            ia += 1
        if ia >= Na:
            print('A')
            sys.exit()
        t = Sa[ia]
        ia += 1
    if t == 'b':
        while ib < Nb and Sb[ib] == 'b':
            ib += 1
        if ib >= Nb:
            print('B')
            sys.exit()
        t = Sb[ib]
        ib += 1
    if t == 'c':
        while ic < Nc and Sc[ic] == 'c':
            ic += 1
        if ic >= Nc:
            print('C')
            sys.exit()
        t = Sc[ic]
        ic += 1
