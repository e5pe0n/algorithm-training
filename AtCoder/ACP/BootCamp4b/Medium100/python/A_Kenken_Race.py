import sys
N, A, B, C, D = list(map(int, input().split()))
S = input()
A -= 1
B -= 1
C -= 1
D -= 1
if C < D:
    i = A
    while i < C:
        while i < C and S[i] == '.':
            i += 1
        _cnt_r = 0
        while i < C and S[i] == '#':
            i += 1
            _cnt_r += 1
        if _cnt_r >= 2:
            print('No')
            sys.exit()
    i = B
    while i < D:
        while i < D and S[i] == '.':
            i += 1
        _cnt_r = 0
        while i < D and S[i] == '#':
            i += 1
            _cnt_r += 1
        if _cnt_r >= 2:
            print('No')
            sys.exit()
    print('Yes')
else:
    i = B - 1
    cnt_s = 0
    while i <= D + 1:
        _cnt_s = 0
        while i <= D + 1 and S[i] == '.':
            i += 1
            _cnt_s += 1
        cnt_s = max(cnt_s, _cnt_s)
        _cnt_r = 0
        while i <= D + 1 and S[i] == '#':
            i += 1
            _cnt_r += 1
        if _cnt_r >= 2:
            print('No')
            sys.exit()
    if cnt_s <= 2:
        print('No')
        sys.exit()
    i = A
    while i < C:
        while i < C and S[i] == '.':
            i += 1
        _cnt_r = 0
        while i < C and S[i] == '#':
            i += 1
            _cnt_r += 1
        if _cnt_r >= 2:
            print('No')
            sys.exit()
    print('Yes')
