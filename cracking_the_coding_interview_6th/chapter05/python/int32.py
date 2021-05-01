import operator
from typing import Union


class Int32:
    MAX = 2**31 - 1
    MIN = -2**31
    BIT_NUMS = 32

    def __init__(self, value: Union[int, str]):
        if isinstance(value, int):
            if not (self.MIN <= value <= self.MAX):
                raise ValueError(
                    f"value must be an int object within 32-bit integer value, \
                        [{self.MIN}, {self.MAX}].")
            if value >= 0:
                self.value = value
                self.__bin = value
            else:
                self.value = value
                self.__bin = self.__bin_signed(self.__cmpl(value))

        elif isinstance(value, str):
            if len(value) > self.BIT_NUMS:
                raise ValueError("value length must be between [1, 32].")
            if len(value) == 32 and value[0] == '1':
                r_31 = int(value[1:], 2)
                self.__bin = self.__bin_signed(r_31)
                self.value = -self.__cmpl(r_31)
            else:
                self.value = int(value, 2)
                self.__bin = self.value
        else:
            raise ValueError("value must be an int or a str object.")

    def __bin_signed(self, r_31):
        return r_31 | (1 << (self.BIT_NUMS - 1))

    def __cmpl(self, n):
        return self.MAX + 1 - n

    def __apply_op(self, this, other, op):
        if isinstance(other, int):
            res = op(this, other)
        elif isinstance(other, Int32):
            res = op(this, other.value)
        else:
            raise ValueError(
                f"another operand must be an Int32 or int object \
                within 32-bit integer value, [{self.MIN}, {self.MAX}].")
        return res

    def __apply_num_op(self, other, op):
        return self.__apply_op(self.value, other, op)

    def __apply_bit_op(self, other, op):
        return self.__apply_op(self.__bin, other, op)

    def __validate(self, n):
        if self.MIN <= n <= self.MAX:
            return Int32(n)
        elif n < self.MIN:
            raise ValueError("underflow in 32 bit integer.")
        else:
            raise ValueError("overflow in 32 bit integer.")

    def __abs__(self):
        return abs(self.value)

    def __neg__(self):
        return Int32(self.value)

    def __add__(self, other):
        res = self.__apply_num_op(other, operator.add)
        return self.__validate(res)

    def __sub__(self, other):
        res = self.__apply_num_op(other, operator.sub)
        return self.__validate(res)

    def __mul__(self, other):
        res = self.__apply_num_op(other, operator.mul)
        return self.__validate(res)

    def __truediv__(self, other):
        res = self.__apply_num_op(other, operator.truediv)
        return self.__validate(res)

    def __floordiv__(self, other):
        res = self.__apply_num_op(other, operator.floordiv)
        return self.__validate(res)

    def __mod__(self, other):
        res = self.__apply_num_op(other, operator.mod)
        return self.__validate(res)

    def __pow__(self, other):
        res = self.__apply_num_op(other, operator.pow)
        return self.__validate(res)

    def __and__(self, other):
        res = self.__apply_bit_op(other, operator.and_)
        return self.__validate(res)

    def __or__(self, other):
        res = self.__apply_bit_op(other, operator.or_)
        return self.__validate(res)

    def __xor__(self, other):
        res = self.__apply_bit_op(other, operator.xor)
        return res

    def __lshift__(self, other):
        if isinstance(other, int):
            shift = other
        elif isinstance(other, Int32):
            shift = other.value
        else:
            raise ValueError("another operand must be an Int32 or int object.")
        this_s = f"{self.__bin:032b}"
        cnt_0 = max(self.BIT_NUMS, shift)
        res_s = this_s[shift:] + ('0' * cnt_0)
        return Int32(res_s)

    def __rshift__(self, other):
        if isinstance(other, int):
            shift = other
        elif isinstance(other, Int32):
            shift = other.value
        else:
            raise ValueError("another operand must be an Int32 or int object.")
        this_s = f"{self.__bin:032b}"
        cnt_0 = max(self.BIT_NUMS, shift)
        res_s = ('0' * cnt_0) + this_s[:-shift]
        return Int32(res_s)
