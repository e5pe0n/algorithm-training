MAX_COLOR = 4


class Res:
    def __init__(self, hits: int = 0, pseudo_hits: int = 0):
        self.hits: int = hits
        self.pseudo_hits: int = pseudo_hits

    def __repr__(self):
        return f"hits={self.hits}, pseudo_hits={self.pseudo_hits}"


def code(c: str):
    d = {
        'B': 0,
        'G': 1,
        'R': 2,
        'Y': 3
    }
    return d.get(c, -1)


def estimate(guess: str, sol: str) -> Res:
    if len(guess) != len(sol):
        raise ValueError("guess ans sol must be the same length.")
    res = Res()
    freq = [0] * MAX_COLOR
    for i in range(len(guess)):
        if guess[i] == sol[i]:
            res.hits += 1
        else:
            freq[code(sol[i])] += 1
    for i in range(len(guess)):
        c = code(guess[i])
        if c >= 0 and freq[c] > 0 and guess[i] != sol[i]:
            res.pseudo_hits += 1
            freq[c] -= 1
    return res


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        sol = ns(f)
        guess = ns(f)
    print(estimate(guess, sol))
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
