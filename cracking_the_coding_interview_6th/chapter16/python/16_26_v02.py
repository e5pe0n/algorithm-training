from __future__ import annotations
from typing import List, Union
from enum import Enum, auto
import re


class Term:
    class Operator(Enum):
        ADD = auto()
        SUB = auto()
        MUL = auto()
        DIV = auto()
        BLANK = auto()

    @classmethod
    def parse_term_seq(cls, seq: str) -> List[Term]:
        res = []
        pat = re.compile(r"([\+\-\*\/]?)([0-9]+)")
        for m in pat.finditer(seq):
            if m[1] == '+':
                res.append(Term(float(m[2]), cls.Operator.ADD))
            elif m[1] == '-':
                res.append(Term(float(m[2]), cls.Operator.SUB))
            elif m[1] == '*':
                res.append(Term(float(m[2]), cls.Operator.MUL))
            elif m[1] == '/':
                res.append(Term(float(m[2]), cls.Operator.DIV))
            else:
                res.append(Term(float(m[2]), cls.Operator.BLANK))
        return res

    def __init__(self, v: float, op: Operator):
        self.v: float = v
        self.op: self.Operator = op


def apply_op(left: float, op: Term.Operator, right: float) -> float:
    if op is Term.Operator.ADD:
        return left + right
    elif op is Term.Operator.SUB:
        return left - right
    elif op is Term.Operator.MUL:
        return left * right
    elif op is Term.Operator.DIV:
        return left / right
    else:
        return right


def collapse_term(primary: Union[Term, None], secondary: Union[Term, None]) -> Term:
    if primary is None:
        return secondary
    if secondary is None:
        return primary
    v = apply_op(primary.v, secondary.op, secondary.v)
    primary.v = v
    return primary


def compute(seq: str) -> float:
    terms = Term.parse_term_seq(seq)
    res = 0
    processing = None
    for i in range(len(terms)):
        curr = terms[i]
        nxt = terms[i + 1] if i + 1 < len(terms) else None
        processing = collapse_term(processing, curr)
        if nxt is None or nxt.op is Term.Operator.ADD or nxt.op is Term.Operator.SUB:
            res = apply_op(res, processing.op, processing.v)
            processing = None
    return res


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        expr = ns(f)
    print(compute(expr))
    print()


solve("../testcases/16_26/01.txt")
solve("../testcases/16_26/02.txt")
solve("../testcases/16_26/03.txt")

# # ../testcases/16_26/01.txt
# 23.5

# # ../testcases/16_26/02.txt
# 120.0

# # ../testcases/16_26/03.txt
# 99.0
