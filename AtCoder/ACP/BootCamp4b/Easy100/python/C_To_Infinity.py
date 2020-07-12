S = input()
K = int(input())
if S[0] == '1':
    if K == 1:
        print('1')
    else:
        for i in range(1, len(S)):
            if S[i] != '1':
                break
        if i <= K - 1:
            print(S[i])
        else:
            print('1')
else:
    print(S[0])
