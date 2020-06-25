from typing import List


def solve(S: str):
    idxs = []
    for i in range(len(S)):
        if S[i].isupper():
            idxs.append(i)

    ws = []
    for i in range(0, len(idxs), 2):
        w = S[idxs[i]:idxs[i + 1] + 1]
        ws.append(w[0].lower() + w[1:-1] + w[-1].lower())

    ws.sort()
    res = ''.join([w[0].upper() + w[1:-1] + w[-1].upper() for w in ws])
    print(res)


cases = {
    'case1': 'FisHDoGCaTAAAaAAbCAC',
    'case2': 'AAAAAjhfgaBCsahdfakGZsZGdEAA'
}

for k, v in cases.items():
    print(f'[{k}]')
    solve(v)
    print()
