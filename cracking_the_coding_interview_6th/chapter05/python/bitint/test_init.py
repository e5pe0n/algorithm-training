import pytest

from bitint import Int32


INT32_MAX = 2**31 - 1
INT32_MIN = -2**31


def test_init_int_plus():
    n = Int32(100)
    assert 100 == n.value
    assert 100 == n.bin


def test_init_int_max_plus():
    n = Int32(INT32_MAX)
    assert INT32_MAX == n.value
    assert INT32_MAX == n.bin


def test_init_int_minus():
    n = Int32(-100)
    assert -100 == n.value
    assert 4294967196 == n.bin


def test_init_int_min_minus():
    n = Int32(INT32_MIN)
    assert INT32_MIN == n.value
    assert 2147483648 == n.bin


def test_init_int_0():
    n = Int32(0)
    assert 0 == n.value
    assert 0 == n.bin


def test_init_int_minus_1():
    n = Int32(-1)
    assert -1 == n.value
    assert 4294967295 == n.bin


def test_init_str_plus():
    n = Int32("1100100")
    assert 100 == n.value
    assert 100 == n.bin


def test_init_str_max_plus():
    n = Int32("01111111111111111111111111111111")
    assert INT32_MAX == n.value
    assert INT32_MAX == n.bin


def test_init_str_minus():
    n = Int32("11001000101110101011010011010001")
    assert -927288111 == n.value
    assert 3367679185 == n.bin


def test_init_str_min_minus():
    n = Int32("10000000000000000000000000000000")
    assert INT32_MIN == n.value
    assert 2147483648 == n.bin


def test_init_str_0():
    n = Int32('0')
    assert 0 == n.value
    assert 0 == n.bin


def test_init_str_minus_1():
    n = Int32("11111111111111111111111111111111")
    assert -1 == n.value
    assert 4294967295 == n.bin


def test_init_str_surplus_length():
    n = Int32("1111111111111111111100000000000000000000")
    assert -1048576 == n.value
    assert 4293918720 == n.bin


def test_init_invalid_type():
    with pytest.raises(TypeError):
        Int32([0, 1, 2, 3, 4, 5])


def test_init_invalid_value_int_plus():
    with pytest.raises(ValueError):
        Int32(INT32_MAX + 1)


def test_init_invalid_value_int_minus():
    with pytest.raises(ValueError):
        Int32(INT32_MIN - 1)


def test_init_invalid_value_str_invalid_char():
    with pytest.raises(ValueError):
        Int32("01234")


def test_init_invalid_value_str_empty():
    with pytest.raises(ValueError):
        Int32("")
