from typing import List


n = 9
m = 5
extracted = [0] * m
skip = [False] * (m + 1)


def off_line_minimum(m: int, n: int, K: List[List[int]]):
    cnt = 0
    for i in range(n + 1):
        for j in range(m):
            if skip[j]:
                continue
            for k in range(len(K[j])):
                if K[j][k] == i:
                    extracted[j] = i
                    skip[j] = True
                    cnt += 1
                    if cnt >= m:
                        return
                    break
            if skip[j]:
                r = j + 1
                while skip[r]:
                    r += 1
                for k in range(len(K[j])):
                    if K[j][k] != i:
                        K[r].append(K[j][k])
                K[j] = []
                break


K = [[8, 2], [4, 5], [], [3, 6, 9], [1, 0], [7]]
off_line_minimum(m, n, K)
print(extracted)    # [2, 4, 5, 3, 0]
