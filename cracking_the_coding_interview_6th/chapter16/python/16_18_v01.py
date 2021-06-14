from typing import Iterable, Union
from collections import Counter


class MatchRes:
    def __init__(self, match: bool,
                 sa: Union[str, Iterable[str]] = None,
                 sb: Union[str, Iterable[str]] = None):
        self.match: bool = match
        self.sa: str = ''.join(sa) if isinstance(sa, Iterable) else sa
        self.sb: str = ''.join(sb) if isinstance(sb, Iterable) else sb


def pat_match(val: str, pat: str) -> MatchRes:
    org_pat = pat
    cnt = Counter(pat)
    na = cnt['a']
    nb = cnt['b']
    if na == 0:
        na, nb = nb, na
        pat = 'a' * na
    if nb == 0:
        if len(val) % na:
            return MatchRes(False)
        la = len(val) // na
        sa = list(val[:la])
        idx = 0
        s = []
        for c in pat:
            for _ in range(la):
                s.append(val[idx])
                idx += 1
            if s != sa:
                return MatchRes(False)
        return MatchRes(True, sa if org_pat[0] == 'a' else "", sa if org_pat[0] == 'b' else "")
    for la in range(1, len(val) // na + 1):
        t = len(val) - la * na
        if t == 0 or t % nb != 0:
            continue
        lb = t // nb
        sa, sb = [], []
        idx = 0
        match = True
        for c in pat:
            s = []
            if c == 'a':
                for _ in range(la):
                    s.append(val[idx])
                    idx += 1
                if s == []:
                    continue
                if sa == []:
                    sa = s
                elif s != sa:
                    match = False
                    break
            else:
                for _ in range(lb):
                    s.append(val[idx])
                    idx += 1
                if s == []:
                    continue
                if sb == []:
                    sb = s
                elif s != sb:
                    match = False
                    break
        if match:
            return MatchRes(True, sa, sb)
    return MatchRes(False)


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        val = ns(f)
        n = int(ns(f))
        pats = [ns(f) for _ in range(n)]
    for pat in pats:
        res = pat_match(val, pat)
        print(res.match, end='')
        if res.match:
            print(f" / {res.sa}, {res.sb}", end='')
        print()
    print()


solve("../testcases/16_18/01.txt")
solve("../testcases/16_18/02.txt")
solve("../testcases/16_18/03.txt")

# # ../testcases/16_18/01.txt
# True / cat, go
# True / catcatgocatgo,
# True / c, atcatgocatgo
# True / cat, catgo
# True / , catcatgocatgo
# True / cat, gocatgo

# # ../testcases/16_18/02.txt
# False
# True / catcagocatgo,
# True / c, atcagocatgo
# False
# True / , catcagocatgo
# False

# # ../testcases/16_18/03.txt
# True / cat, cat
# True / catcatcatcatcat,
# True / c, atcatcatcatcat
# True / cat, catcat
# True / , catcatcatcatcat
# True / cat, catcatcat
