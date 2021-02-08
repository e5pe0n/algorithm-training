A = "atcoder"
T = int(input())
for _ in range(T):
    S = input()
    if S > A:
        print(0)
    else:
        j = 0
        while j < len(S) and S[j] == 'a':
            j += 1
        if j == len(S):
            print(-1)
        else:
            if S[j] > 't':
                j -= 1
            print(j)
