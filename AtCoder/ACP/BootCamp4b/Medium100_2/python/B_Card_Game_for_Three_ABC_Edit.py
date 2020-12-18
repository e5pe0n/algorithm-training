S = [input() for _ in range(3)]
idx = [0] * 3
prv, nxt = 0, 0
while True:
    nxt = ord(S[prv][idx[prv]]) - ord('a')
    idx[prv] += 1
    if idx[nxt] >= len(S[nxt]):
        print(chr(ord('A') + nxt))
        exit()
    nxt, prv = prv, nxt
