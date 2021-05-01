from __future__ import annotations
from typing import Callable, Union, Tuple
import re
import operator


pat = re.compile(r"[01]+")


class Int:
    def __init__(self, value: Union[int, str], bit: int):
        if bit <= 0:
            raise ValueError("bit must be greater than 0.")

        self.__bit: int = bit
        self.__max: int = (1 << (self.__bit - 1)) - 1
        self.__min: int = -self.__max - 1

        if isinstance(value, int):
            # range check
            if value < self.min:
                raise ValueError(
                    f"underflow in {self.__bit}-bit integer value. \
                        value must be between [{self.__min}, {self.__max}]")
            elif self.max < value:
                raise ValueError(
                    f"overflow in {self.bit}-bit integer value. \
                        value must be between [{self.__min}, {self.__max}]")

            if value >= 0:
                self.__value: int = value
                self.__bin: int = self.__value
            else:
                self.__value: int = value
                self.__bin: int = self.__cmpl(abs(self.__value))

        elif isinstance(value, str):
            if len(value) > self.__bit:
                raise ValueError(f"length of value must be between [1, {self.__bit}].")

            if not pat.match(value):
                raise ValueError("value must be a sequence of 0 and 1.")

            if len(value) == self.__bit and value[0] == '1':
                # MSB is 1 so we must calculate the complement
                self.__bin: int = int(value, 2)
                self.__value: int = -self.__cmpl(self.__bin)
            else:
                self.__value: int = int(value, 2)
                self.__bin: int = self.__value

        else:
            raise TypeError("value must be an int or a str object.")

    @property
    def bit(self) -> int:
        return self.__bit

    @property
    def bin(self) -> int:
        return self.__bin

    @property
    def value(self) -> int:
        return self.__value

    @property
    def max(self) -> int:
        return self.__max

    @property
    def min(self) -> int:
        return self.__min

    def __cmpl(self, n: int) -> int:
        return ((self.__max + 1) << 1) - n

    def __validate_opes(self, other: Union[int, Int]) -> Tuple[Int, Int]:
        if isinstance(other, int):
            return (self, Int(other, self.__bit))
        elif isinstance(other, Int):
            greater_bit = max(self.__bit, other.bit)
            return (Int(self.value, greater_bit), Int(other.value, greater_bit))
        else:
            raise TypeError("operands must be int or Int objects")

    def __apply_num_op(self, ope1: Int, ope2: Int, op: Callable[[int, int], int]) -> Int:
        res = op(ope1.value, ope2.value)
        return Int(res, ope1.bit)

    def __apply_bit_op(self, ope1: Int, ope2: Int, op: Callable[[int, int], int]) -> Int:
        res = op(ope1.bin, ope2.bin)
        return Int(f"{res:0{ope1.bit}b}", ope1.bit)

    def __repr__(self) -> str:
        return f"Int(bit={self.__bit}, value={self.__value}, bin={self.__bin})"

    def __str__(self) -> str:
        return str(self.value)

    def __format__(self, format_spec: str) -> str:
        t = format_spec[-1]
        if t in ('b', 'o', 'x', 'X'):
            return format(self.bin, format_spec)
        else:
            return format(self.value, format_spec)

    def __abs__(self) -> Int:
        return abs(self.__value)

    def __neg__(self) -> Int:
        return Int(-self.__value, self.__bit)

    def __add__(self, other: Union[int, Int]) -> Int:
        ope1, ope2 = self.__validate_opes(other)
        return self.__apply_num_op(ope1, ope2, operator.add)

    def __radd__(self, other: Union[int, Int]) -> Int:
        return self + other

    def __iadd__(self, other: Union[int, Int]) -> Int:
        return self + other

    def __sub__(self, other: Union[int, Int]) -> Int:
        ope1, ope2 = self.__validate_opes(other)
        return self.__apply_num_op(ope1, ope2, operator.sub)

    def __rsub__(self, other: Union[int, Int]) -> Int:
        return -self + other

    def __isub__(self, other: Union[int, Int]) -> Int:
        return self - other

    def __mul__(self, other: Union[int, Int]) -> Int:
        ope1, ope2 = self.__validate_opes(other)
        return self.__apply_num_op(ope1, ope2, operator.mul)

    def __rmul__(self, other: Union[int, Int]) -> Int:
        return self * other

    def __imul__(self, other: Union[int, Int]) -> Int:
        return self * other

    def __truediv__(self, other: Union[int, Int]) -> float:
        ope1, ope2 = self.__validate_opes(other)
        return ope1.value / ope2.value

    def __rtruediv__(self, other: Union[int, Int]) -> float:
        ope1, ope2 = self.__validate_opes(other)
        return ope2.value / ope1.value

    def __itruediv__(self, other: Union[int, Int]) -> float:
        return self / other

    def __floordiv__(self, other: Union[int, Int]) -> Int:
        ope1, ope2 = self.__validate_opes(other)
        return self.__apply_num_op(ope1, ope2, operator.floordiv)

    def __rfloordiv__(self, other: Union[int, Int]) -> Int:
        ope1, ope2 = self.__validate_opes(other)
        return self.__apply_num_op(ope2, ope1, operator.floordiv)

    def __ifloordiv__(self, other: Union[int, Int]) -> Int:
        return self // other

    def __mod__(self, other: Union[int, Int]) -> Int:
        ope1, ope2 = self.__validate_opes(other)
        return self.__apply_num_op(ope1, ope2, operator.mod)

    def __rmod__(self, other: Union[int, Int]) -> Int:
        ope1, ope2 = self.__validate_opes(other)
        return self.__apply_num_op(ope2, ope1, operator.mod)

    def __imod__(self, other: Union[int, Int]) -> Int:
        return self % other

    def __pow__(self, other: Union[int, Int]) -> Int:
        ope1, ope2 = self.__validate_opes(other)
        return self.__apply_num_op(ope1, ope2, operator.pow)

    def __rpow__(self, other: Union[int, Int]) -> Int:
        ope1, ope2 = self.__validate_opes(other)
        return self.__apply_num_op(ope2, ope1, operator.pow)

    def __ipow__(self, other: Union[int, Int]) -> Int:
        return self ** other

    def __invert__(self) -> Int:
        return Int(f"{self.__cmpl(self.__bin) - 1:0{self.__bit}b}", self.__bit)

    def __and__(self, other: Union[int, Int]) -> Int:
        ope1, ope2 = self.__validate_opes(other)
        return self.__apply_bit_op(ope1, ope2, operator.and_)

    def __rand__(self, other: Union[int, Int]) -> Int:
        ope1, ope2 = self.__validate_opes(other)
        return self.__apply_bit_op(ope2, ope1, operator.and_)

    def __iand__(self, other: Union[int, Int]) -> Int:
        return self & other

    def __or__(self, other):
        ope1, ope2 = self.__validate_opes(other)
        return self.__apply_bit_op(ope1, ope2, operator.or_)

    def __ror__(self, other: Union[int, Int]) -> Int:
        ope1, ope2 = self.__validate_opes(other)
        return self.__apply_bit_op(ope2, ope1, operator.or_)

    def __ior__(self, other: Union[int, Int]) -> Int:
        return self | other

    def __xor__(self, other):
        ope1, ope2 = self.__validate_opes(other)
        return self.__apply_bit_op(ope1, ope2, operator.xor)

    def __rxor__(self, other: Union[int, Int]) -> Int:
        ope1, ope2 = self.__validate_opes(other)
        return self.__apply_bit_op(ope2, ope1, operator.xor)

    def __ixor__(self, other: Union[int, Int]) -> Int:
        return self ^ other

    def __lshift__(self, other: Union[int, Int]) -> Int:
        ope1, ope2 = self.__validate_opes(other)
        ope1_s = f"{ope1.__bin:0{ope1.__bit}b}"
        shift = ope2.value
        cnt_0 = min(ope1.__bit, shift)
        res_s = ope1_s[shift:] + ('0' * cnt_0)
        return Int(res_s, ope1.__bit)

    def __rlshift__(self, other: Union[int, Int]) -> Int:
        ope1, ope2 = self.__validate_opes(other)
        return ope2 << ope1

    def __ilshift__(self, other: Union[int, Int]) -> Int:
        return self << other

    def __rshift__(self, other: Union[int, Int]) -> Int:
        ope1, ope2 = self.__validate_opes(other)
        ope1_s = f"{ope1.__bin:0{ope1.__bit}b}"
        shift = ope2.value
        cnt = min(ope1.__bit, shift)
        res_s = (ope1_s[0] * cnt) + ope1_s[:-shift]
        return Int(res_s, ope1.__bit)

    def __rrshift__(self, other: Union[int, Int]) -> Int:
        ope1, ope2 = self.__validate_opes(other)
        return ope2 >> ope1

    def __irshift__(self, other: Union[int, Int]) -> Int:
        return self >> other

    def __lt__(self, other) -> bool:
        if isinstance(other, Int):
            return self.value < other.value
        else:
            return self.value < other

    def __le__(self, other) -> bool:
        if isinstance(other, Int):
            return self.value <= other.value
        else:
            return self.value <= other

    def __gt__(self, other) -> bool:
        if isinstance(other, Int):
            return self.value > other.value
        else:
            return self.value > other

    def __ge__(self, other) -> bool:
        if isinstance(other, Int):
            return self.value >= other.value
        else:
            return self.value >= other

    def __eq__(self, other: Union[int, Int]) -> bool:
        if isinstance(other, Int):
            return self.value == other.value
        else:
            return self.value == other

    def __ne__(self, other: Union[int, Int]) -> bool:
        return not (self == other)

    def __bool__(self) -> bool:
        return bool(self.value)

    def __index__(self) -> int:
        return self.bin


def Int16(value):
    return Int(value, 16)


def Int32(value):
    return Int(value, 32)


def Int64(value):
    return Int(value, 64)
