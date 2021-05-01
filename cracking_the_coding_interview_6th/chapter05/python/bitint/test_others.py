import pytest

from bitint import Int32


INT32_MAX = 2**31 - 1
INT32_MIN = -2**31


# bool

def test_bool_0():
    assert (0 or False) == Int32(0)


def test_bool_plus():
    assert (100 or False) == Int32(100)


def test_bool_minus():
    assert (-100 or False) == -Int32(100)


def test_format_b_plus():
    n1 = 100
    n2 = Int32(100)
    assert f"{n1:032b}" == f"{n2:032b}"


# def test_format_b_minus():
#     n1 = -100
#     n2 = -Int32(100)
#     assert f"{n1:032b}" == f"{n2:032b}"


def test_format_d_plus():
    n1 = 100
    n2 = Int32(100)
    assert f"{n1:010d}" == f"{n2:010d}"


def test_format_d_minus():
    n1 = -100
    n2 = -Int32(100)
    assert f"{n1:010d}" == f"{n2:010d}"


def test_format_f_plus():
    n1 = 100
    n2 = Int32(100)
    assert f"{n1:.2f}" == f"{n2:.2f}"


def test_format_f_minus():
    n1 = -100
    n2 = -Int32(100)
    assert f"{n1:.2f}" == f"{n2:.2f}"
