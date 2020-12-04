K = int(input())
cnt = 0  # Lunlun number の数
for d in range(1, 10**9):   # 桁数
    ub = [9] * d    # upper bound
    n = [1] * d     # LunLun number
    i = 0           # index of ub and n
    while n[0] < 10:        # 最初の桁の数値が 9 を超えたら次の桁数にいく
        if n[i] > ub[i]:    # 見ている桁の数値が上端を超えたら 1 つ前の桁の数値を +1
            n[i - 1] += 1
            i -= 1          # 1 つ左の桁にいく
            continue
        if i == d - 1:      # 所定の桁数になったら 1 つ数える
            cnt += 1
            if cnt == K:    # K 番目ならそのときの n を出力して終了
                print(''.join([str(x) for x in n]))
                exit()
            n[i] += 1       # 最後の桁の数値を +1
            continue
        while i < d - 1:    # 所定の桁数に満たない場合
            ub[i + 1] = min(9, n[i] + 1)    # 右の桁の上端を新しく追加
            n[i + 1] = max(0, n[i] - 1)     # 右の桁の数値として下端を設定
            i += 1  # 右の桁にいく
