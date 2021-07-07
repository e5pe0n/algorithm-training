from typing import Dict, List, Tuple
from collections import defaultdict


def _re_space(
    s: str,
    words: Dict[str, List[str]],
    idx: int,
    tmp_spaced: List[str],
    cnt_unrec: int,
    prv: str
) -> Tuple[str, int]:
    if idx == len(s):
        if len(tmp_spaced) == 0:
            return (s, len(s))
        return (" ".join(filter(lambda x: x != "", tmp_spaced)), cnt_unrec)
    best_cnt_unrec = float("inf")
    best_spaced = ""
    for w in words[s[idx]]:
        tmp_spaced.append(prv)
        if cnt_unrec < best_cnt_unrec and w == s[idx:idx + len(w)]:
            tmp_spaced.append(w)
            _spaced, _cnt_unrec = _re_space(s, words, idx + len(w), tmp_spaced, cnt_unrec, "")
            if _cnt_unrec < best_cnt_unrec:
                best_cnt_unrec = _cnt_unrec
                best_spaced = _spaced
                if best_cnt_unrec == 0:
                    break
            tmp_spaced.pop()
        tmp_spaced.pop()
    _spaced, _cnt_unrec = _re_space(s, words, idx + 1, tmp_spaced, cnt_unrec + 1, prv + s[idx])
    return (best_spaced, best_cnt_unrec) if best_cnt_unrec < _cnt_unrec else (_spaced, _cnt_unrec)


def re_space(s: str, words: Dict[str, List[str]]) -> Tuple[str, int]:
    return _re_space(s, words, 0, [], 0, "")


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        s = ns(f)
        n = int(ns(f))
        words = defaultdict(list)
        for _ in range(n):
            w = ns(f)
            words[w[0]].append(w)
    spaced, cnt_unrec = re_space(s, words)
    print(f"{cnt_unrec}, {spaced}")
    print()


solve("../testcases/17_13/01.txt")
solve("../testcases/17_13/02.txt")
solve("../testcases/17_13/03.txt")
