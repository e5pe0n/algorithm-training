import pytest

from bitint import Int32


INT32_MAX = 2**31 - 1
INT32_MIN = -2**31

# invert


def test_invert_0():
    n = ~Int32(0)
    assert -1 == n.value
    assert (1 << 32) - 1 == n.bin


def test_invert_plus_max():
    n = ~Int32(INT32_MAX)
    assert INT32_MIN == n.value
    assert INT32_MAX + 1 == n.bin


def test_invert_plus_mid():
    n = ~Int32(1_000_000_000)
    assert -1_000_000_001 == n.value
    assert 3294967295 == n.bin


def test_invert_munus_1():
    n = ~(-Int32(1))
    assert 0 == n.value
    assert 0 == n.bin


def test_invert_minus_min():
    n = ~(Int32(INT32_MIN))
    assert 2147483647 == n.value
    assert 2147483647 == n.bin


def test_invert_minus_mid():
    n = ~(-Int32(1_000_000_000))
    assert 999999999 == n.value
    assert 999999999 == n.bin

# and_


def test_and_Int_Int():
    n1 = Int32(-772969509)
    n2 = Int32(-1115735145)
    res = n1 & n2
    assert -1855116397 == res.value
    assert 2439850899 == res.bin


def test_and_Int_int():
    n1 = Int32(-772969509)
    n2 = -1115735145
    res = n1 & n2
    assert -1855116397 == res.value
    assert 2439850899 == res.bin

# rand_


def test_rand_int_Int():
    n1 = -772969509
    n2 = Int32(-1115735145)
    res = n1 & n2
    assert -1855116397 == res.value
    assert 2439850899 == res.bin


# iand_
def test_iand_Int_Int():
    n = Int32(-772969509)
    n &= Int32(-1115735145)
    assert -1855116397 == n.value
    assert 2439850899 == n.bin


def test_iand_Int_int():
    n = Int32(-772969509)
    n &= -1115735145
    assert -1855116397 == n.value
    assert 2439850899 == n.bin


def test_iand_int_Int():
    n = -772969509
    n &= Int32(-1115735145)
    assert -1855116397 == n.value
    assert 2439850899 == n.bin

# or_


def test_or_Int_Int():
    n1 = Int32(-772969509)
    n2 = Int32(-1115735145)
    res = n1 | n2
    assert -33588257 == res.value
    assert 4261379039 == res.bin


def test_or_Int_int():
    n1 = Int32(-772969509)
    n2 = -1115735145
    res = n1 | n2
    assert -33588257 == res.value
    assert 4261379039 == res.bin

# ror_


def test_ror_int_Int():
    n1 = -772969509
    n2 = Int32(-1115735145)
    res = n1 | n2
    assert -33588257 == res.value
    assert 4261379039 == res.bin


# ior_
def test_ior_Int_Int():
    n = Int32(-772969509)
    n |= Int32(-1115735145)
    assert -33588257 == n.value
    assert 4261379039 == n.bin


def test_ior_Int_int():
    n = Int32(-772969509)
    n |= -1115735145
    assert -33588257 == n.value
    assert 4261379039 == n.bin


def test_ior_int_Int():
    n = -772969509
    n |= Int32(-1115735145)
    assert -33588257 == n.value
    assert 4261379039 == n.bin

# xor


def test_xor_Int_Int():
    n1 = Int32(-772969509)
    n2 = Int32(-1115735145)
    res = n1 ^ n2
    assert 1821528140 == res.value
    assert 1821528140 == res.bin


def test_xor_Int_int():
    n1 = Int32(-772969509)
    n2 = -1115735145
    res = n1 ^ n2
    assert 1821528140 == res.value
    assert 1821528140 == res.bin

# rxor_


def test_rxor_int_Int():
    n1 = -772969509
    n2 = Int32(-1115735145)
    res = n1 ^ n2
    assert 1821528140 == res.value
    assert 1821528140 == res.bin


# ixor_
def test_ixor_Int_Int():
    n = Int32(-772969509)
    n ^= Int32(-1115735145)
    assert 1821528140 == n.value
    assert 1821528140 == n.bin


def test_ixor_Int_int():
    n = Int32(-772969509)
    n ^= -1115735145
    assert 1821528140 == n.value
    assert 1821528140 == n.bin


def test_ixor_int_Int():
    n = -772969509
    n ^= Int32(-1115735145)
    assert 1821528140 == n.value
    assert 1821528140 == n.bin

# lshft


def test_lsfhit_Int_Int():
    n1 = Int32(-772969509)
    n2 = Int32(10)
    res = n1 << n2
    assert -1246794752 == res.value
    assert 3048172544 == res.bin


def test_lsfhit_Int_int():
    n1 = Int32(-772969509)
    n2 = 10
    res = n1 << n2
    assert -1246794752 == res.value
    assert 3048172544 == res.bin

# rlshift


def test_rlsfhit_int_Int():
    n1 = -772969509
    n2 = Int32(10)
    res = n1 << n2
    assert -1246794752 == res.value
    assert 3048172544 == res.bin


# ilshift
def test_ilsfhit_Int_Int():
    n1 = Int32(-772969509)
    n2 = Int32(10)
    n1 <<= n2
    assert -1246794752 == n1.value
    assert 3048172544 == n1.bin


def test_ilsfhit_Int_int():
    n1 = Int32(-772969509)
    n2 = 10
    n1 <<= n2
    assert -1246794752 == n1.value
    assert 3048172544 == n1.bin


def test_ilsfhit_int_Int():
    n1 = -772969509
    n2 = Int32(10)
    n1 <<= n2
    assert -1246794752 == n1.value
    assert 3048172544 == n1.bin


# rshft
def test_rsfhit_Int_Int():
    n1 = Int32(-772969509)
    n2 = Int32(10)
    res = n1 >> n2
    assert -754854 == res.value
    assert 4294212442 == res.bin


def test_rsfhit_Int_int():
    n1 = Int32(-772969509)
    n2 = 10
    res = n1 >> n2
    assert -754854 == res.value
    assert 4294212442 == res.bin

# rrshift


def test_rrsfhit_int_Int():
    n1 = -772969509
    n2 = Int32(10)
    res = n1 >> n2
    assert -754854 == res.value
    assert 4294212442 == res.bin


# irshift
def test_irsfhit_Int_Int():
    n1 = Int32(-772969509)
    n2 = Int32(10)
    n1 >>= n2
    assert -754854 == n1.value
    assert 4294212442 == n1.bin


def test_irsfhit_Int_int():
    n1 = Int32(-772969509)
    n2 = 10
    n1 >>= n2
    assert -754854 == n1.value
    assert 4294212442 == n1.bin


def test_irsfhit_int_Int():
    n1 = -772969509
    n2 = Int32(10)
    n1 >>= n2
    assert -754854 == n1.value
    assert 4294212442 == n1.bin
