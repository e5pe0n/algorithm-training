from collections import Counter


class Res:
    def __init__(self, hits: int, pseudo_hits: int):
        self.hits = hits
        self.pseudo_hits = pseudo_hits


def master_mind(sol: str, guess: str) -> Res:
    cnt = Counter(sol)
    hits, pseudo_hits = 0, 0
    for c in guess:
        if cnt[c] > 0:
            pseudo_hits += 1
            cnt[c] -= 1
    for s, g in zip(sol, guess):
        if s == g:
            pseudo_hits -= 1
            hits += 1
    return Res(hits, pseudo_hits)


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        sol = ns(f)
        guess = ns(f)
    res = master_mind(sol, guess)
    print(f"hits={res.hits}, pseudo_hits={res.pseudo_hits}")
    print()


solve("../testcases/16_15/01.txt")
solve("../testcases/16_15/02.txt")
solve("../testcases/16_15/03.txt")
solve("../testcases/16_15/04.txt")
solve("../testcases/16_15/05.txt")
solve("../testcases/16_15/06.txt")

# # ../testcases/16_15/01.txt
# hits=1, pseudo_hits=1

# # ../testcases/16_15/02.txt
# hits=0, pseudo_hits=4

# # ../testcases/16_15/03.txt
# hits=4, pseudo_hits=0

# # ../testcases/16_15/04.txt
# hits=0, pseudo_hits=0

# # ../testcases/16_15/05.txt
# hits=1, pseudo_hits=1

# # ../testcases/16_15/06.txt
# hits=2, pseudo_hits=2
