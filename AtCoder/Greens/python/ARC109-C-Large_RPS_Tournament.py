N, K = map(int, input().split())
S = list(input())

win = {'R': {}, 'S': {}, 'P': {}}
win['R']['R'] = win['R']['S'] = win['S']['R'] = 'R'
win['S']['S'] = win['S']['P'] = win['P']['S'] = 'S'
win['P']['P'] = win['P']['R'] = win['R']['P'] = 'P'

for _ in range(K):
    t = (S + S)[::]
    for i in range(N):
        S[i] = win[t[i * 2]][t[i * 2 + 1]]
print(S[0])
