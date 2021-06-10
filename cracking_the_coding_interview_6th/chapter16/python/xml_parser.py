from __future__ import annotations
from typing import List
from functools import partial
import re

cmpl = partial(re.compile, flags=re.DOTALL)

TAG_PAT_R = r"<.*?>"
END_TAG_PAT_R = r"</.*?>"
BODY_PAT_R = r"\s*[^\s<>][^<>]*[^\s<>]\s*"
ELEM_PAT_R = r"(" + TAG_PAT_R + "|" + BODY_PAT_R + ")"
TAG_PAT_C = cmpl(TAG_PAT_R)
END_TAG_PAT_C = cmpl(END_TAG_PAT_R)
BODY_PAT_C = cmpl(BODY_PAT_R)
ELEM_PAT_C = cmpl(ELEM_PAT_R)

TAG_GRP_PAT_R = r"<(\w+)\s*?(.*?)>"
END_TAG_GRP_PAT_R = r"</(\w+)>"
ATTR_GRP_PAT_R = r"([\w-]+)=\"(.*?)\""
TAG_GRP_PAT_C = cmpl(TAG_GRP_PAT_R)
END_TAG_GRP_PAT_C = cmpl(END_TAG_GRP_PAT_R)
ATTR_GRP_PAT_C = cmpl(ATTR_GRP_PAT_R)


class Elem:
    pass


class Element(Elem):
    def __init__(self, name: str, attributes: List[Attribute]):
        self.name = name
        self.attributes = attributes
        self.children = None

    def __repr__(self) -> str:
        return f"<{self.name} {self.attributes}>{self.children}</{self.name}>"


class Body(Elem):
    def __init__(self, text: str):
        self.text = text

    def __repr__(self) -> str:
        return self.text


class Attribute:
    def __init__(self, name: str, value: str):
        self.name = name
        self.value = value

    def __repr__(self) -> str:
        return f'{self.name}="{self.value}"'


def attr_parser(s: str) -> Attribute:
    attrs = []
    for m in ATTR_GRP_PAT_C.finditer(s):
        attrs.append(Attribute(m[1], m[2]))
    return attrs


def parser(s: str) -> Elem:
    stack: List[Elem] = []
    for m in ELEM_PAT_C.finditer(s):
        if _m := END_TAG_GRP_PAT_C.match(m[0]):
            children = []
            while stack and (
                not isinstance(stack[-1], Element)
                or stack[-1].name != _m[1]
                or stack[-1].children is not None
            ):
                children.append(stack.pop())
            stack[-1].children = children[::-1] if len(children) else children
        elif _m := TAG_GRP_PAT_C.match(m[0]):
            stack.append(Element(_m[1], attr_parser(_m[2])))
        else:
            stack.append(Body(m[0]))
    return stack[-1]


def main():
    with open("../testcases/16_11/03.xml") as f:
        s = f.read()

    print(s)
    print()

    elem = parser(s)
    print(elem)


if __name__ == "__main__":
    main()
