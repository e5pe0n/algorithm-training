from copy import deepcopy
from itertools import permutations

H, W, K = map(int, input().split())
C = [list(input()) for _ in range(H)]

res = 0
for h in range(H + 1):
    BH = [0] * (H - h) + [1] * h
    perm_h = set(permutations(BH))
    for ph in perm_h:
        for w in range(W + 1):
            BW = [0] * (W - w) + [1] * w
            perm_w = set(permutations(BW))
            for pw in perm_w:
                _C = deepcopy(C)
                for i in range(H):
                    if ph[i]:
                        for j in range(W):
                            _C[i][j] = 'R'
                for j in range(W):
                    if pw[j]:
                        for i in range(H):
                            _C[i][j] = 'R'
                cnt = 0
                for i in range(H):
                    for j in range(W):
                        if _C[i][j] == '#':
                            cnt += 1
                if cnt == K:
                    res += 1

print(res)
