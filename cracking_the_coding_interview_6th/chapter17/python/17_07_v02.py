from typing import List, Dict, Tuple, MutableSet
from collections import defaultdict, deque


def cnt_synonyms(
    G: Dict[str, List[str]],
    name_freq: Dict[str, int],
    used: MutableSet[str],
    s: str
) -> int:
    q = deque([s])
    used.add(s)
    cnt = name_freq[s]
    while q:
        u = q.popleft()
        for v in G[u]:
            if v not in used:
                q.append(v)
                used.add(v)
                cnt += name_freq.get(v, 0)
    return cnt


def cnt_real_freq(name_freq: Dict[str, int], synonyms: List[Tuple[int, int]]) -> Dict[str, int]:
    G = defaultdict(list)
    for name1, name2 in synonyms:
        G[name1].append(name2)
        G[name2].append(name1)
    used = set()
    res = {}
    for name, _ in name_freq.items():
        if name not in used:
            res[name] = cnt_synonyms(G, name_freq, used, name)
    return res


def ns(f):
    return next(f).strip()


def solve(fp_names: str, fp_synonyms: str):
    print(f"# {fp_names} {fp_synonyms}")
    with open(fp_names) as f:
        n = int(ns(f))
        name_freq = {}
        for _ in range(n):
            name, freq = ns(f).split()
            name_freq[name] = int(freq)
    with open(fp_synonyms) as f:
        n = int(ns(f))
        synonyms = [tuple(ns(f).split()) for _ in range(n)]
    res = cnt_real_freq(name_freq, synonyms)
    print(res)
    print()


solve("../testcases/17_07/names01.txt", "../testcases/17_07/synonyms01.txt")
solve("../testcases/17_07/names02.txt", "../testcases/17_07/synonyms02.txt")

# # ../testcases/17_07/names01.txt ../testcases/17_07/synonyms01.txt
# {'John': 27, 'Chris': 36}

# # ../testcases/17_07/names02.txt ../testcases/17_07/synonyms02.txt
# {'cross': 348, 'surface': 269, 'offer': 97, 'magazine': 184, 'release': 249, 'horn': 74, 'value': 42, 'plaintiff': 242, 'disturbance': 178, 'feel': 318, 'amber': 396, 'utter': 8, 'zone': 96, 'body': 41, 'jet': 55, 'embark': 52, 'identity': 92, 'wild': 129, 'gallon': 7, 'tenant': 28}
