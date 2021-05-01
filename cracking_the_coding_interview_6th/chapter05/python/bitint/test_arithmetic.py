import pytest

from bitint import Int32


INT32_MAX = 2**31 - 1
INT32_MIN = -2**31


# abs
def test_abs_plus():
    assert 100 == abs(Int32(100))


def test_abs_minus():
    assert 100 == abs(Int32(-100))


def test_abs_m1():
    assert 1 == abs(Int32(-1))


def test_abs_0():
    assert 0 == abs(Int32(0))

# neg


def test_neg_p2m():
    assert Int32(-100) == -Int32(100)


def test_neg_m2p():
    assert Int32(100) == -Int32(-100)


def test_neg_0():
    assert Int32(0) == -Int32(0)

# add
# Int, Int


def test_add_pInt_pInt():
    assert Int32(199) == Int32(100) + Int32(99)


def test_add_pInt_mInt():
    assert Int32(1) == Int32(100) + -Int32(99)


def test_add_mInt_pInt():
    assert -Int32(1) == -Int32(100) + Int32(99)


def test_add_mInt_mInt():
    assert -Int32(199) == -Int32(100) + -Int32(99)

# Int, int


def test_add_pInt_pint():
    assert Int32(199) == Int32(100) + 99


def test_add_pInt_mint():
    assert Int32(1) == Int32(100) + -99


def test_add_mInt_pint():
    assert -Int32(1) == -Int32(100) + 99


def test_add_mInt_mint():
    assert -Int32(199) == -Int32(100) + -99

# radd


def test_radd_pint_pInt():
    assert Int32(199) == 100 + Int32(99)


def test_radd_pint_mInt():
    assert Int32(1) == 100 + -Int32(99)


def test_radd_mint_pInt():
    assert -Int32(1) == -100 + Int32(99)


def test_radd_mint_mInt():
    assert -Int32(199) == -100 + -Int32(99)


# iadd
def test_iadd_pInt_pInt():
    n = Int32(100)
    n += Int32(99)
    assert Int32(199) == n


def test_iadd_pInt_mInt():
    n = Int32(100)
    n += -Int32(99)
    assert Int32(1) == n


def test_iadd_pInt_pint():
    n = Int32(100)
    n += 99
    assert Int32(199) == n


def test_iadd_pInt_mint():
    n = Int32(100)
    n += -99
    assert Int32(1) == n


def test_iadd_pint_pInt():
    n = 100
    n += Int32(99)
    assert 199 == n


def test_iadd_pint_mInt():
    n = 100
    n += -Int32(99)
    assert 1 == n


def test_iadd_mInt_pInt():
    n = -Int32(100)
    n += Int32(99)
    assert -Int32(1) == n


def test_iadd_mInt_mInt():
    n = -Int32(100)
    n += -Int32(99)
    assert -Int32(199) == n


def test_iadd_mInt_pint():
    n = -Int32(100)
    n += 99
    assert -Int32(1) == n


def test_iadd_mInt_mint():
    n = -Int32(100)
    n += -99
    assert -Int32(199) == n


def test_iadd_mint_pInt():
    n = -100
    n += Int32(99)
    assert -Int32(1) == n


def test_iadd_mint_mInt():
    n = -100
    n += -Int32(99)
    assert -Int32(199) == n

# sub
# Int, Int


def test_sub_pInt_pInt():
    assert Int32(1) == Int32(100) - Int32(99)


def test_sub_pInt_mInt():
    assert Int32(199) == Int32(100) - -Int32(99)


def test_sub_mInt_pInt():
    assert -Int32(199) == -Int32(100) - Int32(99)


def test_sub_mInt_mInt():
    assert -Int32(1) == -Int32(100) - -Int32(99)

# Int, int


def test_sub_pInt_pint():
    assert Int32(1) == Int32(100) - 99


def test_sub_pInt_mint():
    assert Int32(199) == Int32(100) - -99


def test_sub_mInt_pint():
    assert -Int32(199) == -Int32(100) - 99


def test_sub_mInt_mint():
    assert -Int32(1) == -Int32(100) - -99

# rsub


def test_rsub_pint_pInt():
    assert Int32(1) == 100 - Int32(99)


def test_rsub_pint_mInt():
    assert Int32(199) == 100 - -Int32(99)


def test_rsub_mint_pInt():
    assert -Int32(199) == -100 - Int32(99)


def test_rsub_mint_mInt():
    assert -Int32(1) == -100 - -Int32(99)


# isub
def test_isub_pInt_pInt():
    n = Int32(100)
    n -= Int32(99)
    assert Int32(1) == n


def test_isub_pInt_mInt():
    n = Int32(100)
    n -= -Int32(99)
    assert Int32(199) == n


def test_isub_pInt_pint():
    n = Int32(100)
    n -= 99
    assert Int32(1) == n


def test_isub_pInt_mint():
    n = Int32(100)
    n -= -99
    assert Int32(199) == n


def test_isub_pint_pInt():
    n = 100
    n -= Int32(99)
    assert 1 == n


def test_isub_pint_mInt():
    n = 100
    n -= -Int32(99)
    assert 199 == n


def test_isub_mInt_pInt():
    n = -Int32(100)
    n -= Int32(99)
    assert -Int32(199) == n


def test_isub_mInt_mInt():
    n = -Int32(100)
    n -= -Int32(99)
    assert -Int32(1) == n


def test_isub_mInt_pint():
    n = -Int32(100)
    n -= 99
    assert -Int32(199) == n


def test_isub_mInt_mint():
    n = -Int32(100)
    n -= -99
    assert -Int32(1) == n


def test_isub_mint_pInt():
    n = -100
    n -= Int32(99)
    assert -Int32(199) == n


def test_isub_mint_mInt():
    n = -100
    n -= -Int32(99)
    assert -Int32(1) == n

# mul
# Int, Int


def test_mul_pInt_pInt():
    assert Int32(9900) == Int32(100) * Int32(99)


def test_mul_pInt_mInt():
    assert -Int32(9900) == Int32(100) * -Int32(99)


def test_mul_mInt_pInt():
    assert -Int32(9900) == -Int32(100) * Int32(99)


def test_mul_mInt_mInt():
    assert Int32(9900) == -Int32(100) * -Int32(99)

# Int, int


def test_mul_pInt_pint():
    assert Int32(9900) == Int32(100) * 99


def test_mul_pInt_mint():
    assert -Int32(9900) == Int32(100) * -99


def test_mul_mInt_pint():
    assert -Int32(9900) == -Int32(100) * 99


def test_mul_mInt_mint():
    assert Int32(9900) == -Int32(100) * -99

# rmul


def test_rmul_pint_pInt():
    assert Int32(9900) == 100 * Int32(99)


def test_rmul_pint_mInt():
    assert -Int32(9900) == 100 * -Int32(99)


def test_rmul_mint_pInt():
    assert -Int32(9900) == -100 * Int32(99)


def test_rmul_mint_mInt():
    assert Int32(9900) == -100 * -Int32(99)


# imul
def test_imul_pInt_pInt():
    n = Int32(100)
    n *= Int32(99)
    assert Int32(9900) == n


def test_imul_pInt_mInt():
    n = Int32(100)
    n *= -Int32(99)
    assert -Int32(9900) == n


def test_imul_pInt_pint():
    n = Int32(100)
    n *= 99
    assert Int32(9900) == n


def test_imul_pInt_mint():
    n = Int32(100)
    n *= -99
    assert -Int32(9900) == n


def test_imul_pint_pInt():
    n = 100
    n *= Int32(99)
    assert 9900 == n


def test_imul_pint_mInt():
    n = 100
    n *= -Int32(99)
    assert -9900 == n


def test_imul_mInt_pInt():
    n = -Int32(100)
    n *= Int32(99)
    assert -Int32(9900) == n


def test_imul_mInt_mInt():
    n = -Int32(100)
    n *= -Int32(99)
    assert Int32(9900) == n


def test_imul_mInt_pint():
    n = -Int32(100)
    n *= 99
    assert -Int32(9900) == n


def test_imul_mInt_mint():
    n = -Int32(100)
    n *= -99
    assert Int32(9900) == n


def test_imul_mint_pInt():
    n = -100
    n *= Int32(99)
    assert -Int32(9900) == n


def test_imul_mint_mInt():
    n = -100
    n *= -Int32(99)
    assert Int32(9900) == n

# truediv
# Int, Int


def test_truediv_pInt_pInt():
    assert 100 / 99 == Int32(100) / Int32(99)


def test_truediv_pInt_mInt():
    assert 100 / -99 == Int32(100) / -Int32(99)


def test_truediv_mInt_pInt():
    assert -100 / 99 == -Int32(100) / Int32(99)


def test_truediv_mInt_mInt():
    assert -100 / -99 == -Int32(100) / -Int32(99)

# Int, int


def test_truediv_pInt_pint():
    assert 100 / 99 == Int32(100) / 99


def test_truediv_pInt_mint():
    assert 100 / -99 == Int32(100) / -99


def test_truediv_mInt_pint():
    assert -100 / 99 == -Int32(100) / 99


def test_truediv_mInt_mint():
    assert -100 / -99 == -Int32(100) / -99

# rtruediv


def test_rtruediv_pint_pInt():
    assert 100 / 99 == 100 / Int32(99)


def test_rtruediv_pint_mInt():
    assert 100 / -99 == 100 / -Int32(99)


def test_rtruediv_mint_pInt():
    assert -100 / 99 == -100 / Int32(99)


def test_rtruediv_mint_mInt():
    assert -100 / -99 == -100 / -Int32(99)


# itruediv
def test_itruediv_pInt_pInt():
    n = Int32(100)
    n /= Int32(99)
    assert 100 / 99 == n


def test_itruediv_pInt_mInt():
    n = Int32(100)
    n /= -Int32(99)
    assert 100 / -99 == n


def test_itruediv_pInt_pint():
    n = Int32(100)
    n /= 99
    assert 100 / 99 == n


def test_itruediv_pInt_mint():
    n = Int32(100)
    n /= -99
    assert 100 / -99 == n


def test_itruediv_pint_pInt():
    n = 100
    n /= Int32(99)
    assert 100 / 99 == n


def test_itruediv_pint_mInt():
    n = 100
    n /= -Int32(99)
    assert 100 / -99 == n


def test_itruediv_mInt_pInt():
    n = -Int32(100)
    n /= Int32(99)
    assert -100 / 99 == n


def test_itruediv_mInt_mInt():
    n = -Int32(100)
    n /= -Int32(99)
    assert -100 / -99 == n


def test_itruediv_mInt_pint():
    n = -Int32(100)
    n /= 99
    assert -100 / 99 == n


def test_itruediv_mInt_mint():
    n = -Int32(100)
    n /= -99
    assert -100 / -99 == n


def test_itruediv_mint_pInt():
    n = -100
    n /= Int32(99)
    assert -100 / 99 == n


def test_itruediv_mint_mInt():
    n = -100
    n /= -Int32(99)
    assert -100 / -99 == n

# floordiv
# Int, Int


def test_floordiv_pInt_pInt():
    assert 100 // 99 == Int32(100) // Int32(99)


def test_floordiv_pInt_mInt():
    assert 100 // -99 == Int32(100) // -Int32(99)


def test_floordiv_mInt_pInt():
    assert -100 // 99 == -Int32(100) // Int32(99)


def test_floordiv_mInt_mInt():
    assert -100 // -99 == -Int32(100) // -Int32(99)

# Int, int


def test_floordiv_pInt_pint():
    assert 100 // 99 == Int32(100) // 99


def test_floordiv_pInt_mint():
    assert 100 // -99 == Int32(100) // -99


def test_floordiv_mInt_pint():
    assert -100 // 99 == -Int32(100) // 99


def test_floordiv_mInt_mint():
    assert -100 // -99 == -Int32(100) // -99

# rfloordiv


def test_rfloordiv_pint_pInt():
    assert 100 // 99 == 100 // Int32(99)


def test_rfloordiv_pint_mInt():
    assert 100 // -99 == 100 // -Int32(99)


def test_rfloordiv_mint_pInt():
    assert -100 // 99 == -100 // Int32(99)


def test_rfloordiv_mint_mInt():
    assert -100 // -99 == -100 // -Int32(99)


# ifloordiv
def test_ifloordiv_pInt_pInt():
    n = Int32(100)
    n //= Int32(99)
    assert 100 // 99 == n


def test_ifloordiv_pInt_mInt():
    n = Int32(100)
    n //= -Int32(99)
    assert 100 // -99 == n


def test_ifloordiv_pInt_pint():
    n = Int32(100)
    n //= 99
    assert 100 // 99 == n


def test_ifloordiv_pInt_mint():
    n = Int32(100)
    n //= -99
    assert 100 // -99 == n


def test_ifloordiv_pint_pInt():
    n = 100
    n //= Int32(99)
    assert 100 // 99 == n


def test_ifloordiv_pint_mInt():
    n = 100
    n //= -Int32(99)
    assert 100 // -99 == n


def test_ifloordiv_mInt_pInt():
    n = -Int32(100)
    n //= Int32(99)
    assert -100 // 99 == n


def test_ifloordiv_mInt_mInt():
    n = -Int32(100)
    n //= -Int32(99)
    assert -100 // -99 == n


def test_ifloordiv_mInt_pint():
    n = -Int32(100)
    n //= 99
    assert -100 // 99 == n


def test_ifloordiv_mInt_mint():
    n = -Int32(100)
    n //= -99
    assert -100 // -99 == n


def test_ifloordiv_mint_pInt():
    n = -100
    n //= Int32(99)
    assert -100 // 99 == n


def test_ifloordiv_mint_mInt():
    n = -100
    n //= -Int32(99)
    assert -100 // -99 == n

# mod
# Int, Int


def test_mod_pInt_pInt():
    assert 100 % 99 == Int32(100) % Int32(99)


def test_mod_pInt_mInt():
    assert 100 % -99 == Int32(100) % -Int32(99)


def test_mod_mInt_pInt():
    assert -100 % 99 == -Int32(100) % Int32(99)


def test_mod_mInt_mInt():
    assert -100 % -99 == -Int32(100) % -Int32(99)

# Int, int


def test_mod_pInt_pint():
    assert 100 % 99 == Int32(100) % 99


def test_mod_pInt_mint():
    assert 100 % -99 == Int32(100) % -99


def test_mod_mInt_pint():
    assert -100 % 99 == -Int32(100) % 99


def test_mod_mInt_mint():
    assert -100 % -99 == -Int32(100) % -99

# rmod


def test_rmod_pint_pInt():
    assert 100 % 99 == 100 % Int32(99)


def test_rmod_pint_mInt():
    assert 100 % -99 == 100 % -Int32(99)


def test_rmod_mint_pInt():
    assert -100 % 99 == -100 % Int32(99)


def test_rmod_mint_mInt():
    assert -100 % -99 == -100 % -Int32(99)


# imod
def test_imod_pInt_pInt():
    n = Int32(100)
    n %= Int32(99)
    assert 100 % 99 == n


def test_imod_pInt_mInt():
    n = Int32(100)
    n %= -Int32(99)
    assert 100 % -99 == n


def test_imod_pInt_pint():
    n = Int32(100)
    n %= 99
    assert 100 % 99 == n


def test_imod_pInt_mint():
    n = Int32(100)
    n %= -99
    assert 100 % -99 == n


def test_imod_pint_pInt():
    n = 100
    n %= Int32(99)
    assert 100 % 99 == n


def test_imod_pint_mInt():
    n = 100
    n %= -Int32(99)
    assert 100 % -99 == n


def test_imod_mInt_pInt():
    n = -Int32(100)
    n %= Int32(99)
    assert -100 % 99 == n


def test_imod_mInt_mInt():
    n = -Int32(100)
    n %= -Int32(99)
    assert -100 % -99 == n


def test_imod_mInt_pint():
    n = -Int32(100)
    n %= 99
    assert -100 % 99 == n


def test_imod_mInt_mint():
    n = -Int32(100)
    n %= -99
    assert -100 % -99 == n


def test_imod_mint_pInt():
    n = -100
    n %= Int32(99)
    assert -100 % 99 == n


def test_imod_mint_mInt():
    n = -100
    n %= -Int32(99)
    assert -100 % -99 == n

# pow
# Int, Int


def test_pow_pInt_pInt():
    assert 3 ** 10 == Int32(3) ** Int32(10)


def test_pow_mInt_pInt():
    assert (-3) ** 10 == (-Int32(3)) ** Int32(10)


# Int, int


def test_pow_pInt_pint():
    assert 3 ** 10 == Int32(3) ** 10


def test_pow_mInt_pint():
    assert (-3) ** 10 == (-Int32(3)) ** 10


# rpow


def test_rpow_pint_pInt():
    assert 3 ** 10 == 3 ** Int32(10)


def test_rpow_mint_pInt():
    assert (-3) ** 10 == (-3) ** Int32(10)


# ipow
def test_ipow_pInt_pInt():
    n = Int32(3)
    n **= Int32(10)
    assert 3 ** 10 == n


def test_ipow_pInt_pint():
    n = Int32(3)
    n **= 10
    assert 3 ** 10 == n


def test_ipow_pint_pInt():
    n = 3
    n **= Int32(10)
    assert 3 ** 10 == n


def test_ipow_mInt_pInt():
    n = -Int32(3)
    n **= Int32(10)
    assert (-3) ** 10 == n


def test_ipow_mInt_pint():
    n = -Int32(3)
    n **= 10
    assert (-3) ** 10 == n


def test_ipow_mint_pInt():
    n = -3
    n **= Int32(10)
    assert (-3) ** 10 == n
