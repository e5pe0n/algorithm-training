from typing import List, TypeVar, Dict, Tuple
from collections import Counter

T = TypeVar("T")


class FindUnionTree:
    def __init__(self, v: List[T]):
        self.par: Dict[T, T] = {_v: _v for _v in v}
        self.rnk: Dict[T, int] = {_v: 0 for _v in v}

    def find(self, u: T) -> T:
        if u == self.par[u]:
            return u
        self.par[u] = self.find(self.par[u])
        return self.par[u]

    def unite(self, u: T, v: T) -> None:
        u = self.find(u)
        v = self.find(v)
        if u == v:
            return
        if self.rnk[u] < self.rnk[v]:
            self.par[u] = v
        else:
            self.par[v] = u
            if self.rnk[u] == self.rnk[v]:
                self.rnk[u] += 1

    def same(self, u: T, v: T) -> bool:
        return self.find(u) == self.find(v)


def cnt_real_freq(name_freq: Dict[str, int], synonyms: List[Tuple[str, str]]) -> Dict[str, int]:
    fut = FindUnionTree(list(name_freq.keys()) +
                        list(map(lambda x: x[0], synonyms)) + list(map(lambda x: x[1], synonyms)))
    for name1, name2 in synonyms:
        fut.unite(name1, name2)
    cnt = Counter()
    for name, freq in name_freq.items():
        cnt[fut.find(name)] += freq
    return dict(cnt)


def ns(f):
    return next(f).strip()


def solve(fp_names: str, fp_synonyms: str):
    print(f"# {fp_names}")
    with open(fp_names) as f:
        n = int(ns(f))
        names = {}
        for _ in range(n):
            name, freq = ns(f).split()
            names[name] = int(freq)
    with open(fp_synonyms) as f:
        n = int(ns(f))
        synonyms = [ns(f).split() for _ in range(n)]
    res = cnt_real_freq(names, synonyms)
    print(res)
    print()


solve("../testcases/17_07/names01.txt", "../testcases/17_07/synonyms01.txt")
solve("../testcases/17_07/names02.txt", "../testcases/17_07/synonyms02.txt")

# # ../testcases/17_07/names01.txt
# {'Jon': 27, 'Chris': 36}

# # ../testcases/17_07/names02.txt
# {'community': 348, 'swallow': 269, 'offer': 97, 'mislead': 184, 'report': 249, 'horn': 74, 'value': 42, 'pardon': 242, 'dictate': 178, 'fortune': 318, 'authorise': 396, 'utter': 8, 'zone': 96, 'body': 41, 'jet': 55, 'embark': 52, 'identity': 92, 'wild': 129, 'gallon': 7, 'tenant': 28}
