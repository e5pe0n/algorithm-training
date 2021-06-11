from xml_parser import *
from typing import List, Dict


END = "0"


def _encode(elem: Elem, code_map: Dict[str, int]) -> List[str]:
    if isinstance(elem, Body):
        return [elem.text]
    res = [code_map[elem.name]]
    for attr in elem.attributes:
        res.append(code_map[attr.name])
        res.append(attr.value)
    res.append(END)
    for child in elem.children:
        res += _encode(child, code_map)
    res.append(END)
    return res


def encode(elem: Element, code_map: Dict[str, int]) -> List[str]:
    return _encode(elem, code_map)


def ns(f):
    return next(f).strip()


def solve(xml_path: str, txt_path: str):
    print(f"# {xml_path} / {txt_path}")
    with open(xml_path) as f:
        xml = f.read()
    with open(txt_path) as f:
        n = int(ns(f))
        code_map = {k: v for k, v in (ns(f).split() for _ in range(n))}
    elem = parser(xml)
    print(' '.join(encode(elem, code_map)))
    print()


solve("../testcases/16_11/01.xml", "../testcases/16_11/01.txt")
solve("../testcases/16_11/02.xml", "../testcases/16_11/02.txt")
solve("../testcases/16_11/03.xml", "../testcases/16_11/03.txt")

# # ../testcases/16_11/01.xml / ../testcases/16_11/01.txt
# 1 4 McDowell 5 CA 0 2 3 Gayle 0 Some Message 0 0

# # ../testcases/16_11/02.xml / ../testcases/16_11/02.txt
# 1 6 card 7 width: 18rem; 0 2 8 ... 6 card-img-top 9 ... 0 0 1 6 card-body 0 3 6 card-title 0 Card title 0 4 6 card-text 0 Some quick example text to build on the card title and make up the bulk of the card's content. 0 5 10 # 6 btn btn-primary 0 Go somewhere 0 0 0

# # ../testcases/16_11/03.xml / ../testcases/16_11/03.txt
# 9 0 1 10 outer 11 v1-2 0 1 12 inner 0 Inner elem1 0 0 2 0 Elem2 0 3 13 v3-1 14 v3-2 15 v3-3 0 4 0 5 0 Choose one!! 0 6 16 op1 0 7 17 op1 0 Option 1 0 7 17 op2 0 Option 2 0 7 17 op3 0 Option 3 0 7 17 op4 0 Option 4 0 0 0 8 18 margin: 5px; 0 Click me!! 0 0 0
