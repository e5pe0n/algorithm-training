import random

fp = "06.txt"
n = 5
m = 5
mat = [[int(random.uniform(0, 10)) for _ in range(m)] for _ in range(n)]

ma = -float('inf')
for start_i in range(n):
    for start_j in range(m):
        for end_i in range(start_i + 1, n + 1):
            for end_j in range(start_j + 1, m + 1):
                s = 0
                for i in range(start_i, end_i):
                    for j in range(start_j, end_j):
                        s += mat[i][j]
                if ma < s:
                    ma = s
                    res = ((start_i, start_j), (end_i - 1, end_j - 1))

mat_s = '\n'.join(map(lambda x: ' '.join(map(str, x)), mat))

with open(fp, "w") as f:
    f.write(f"{n} {m}\n{mat_s}\n\nans: {ma}, {res}")
