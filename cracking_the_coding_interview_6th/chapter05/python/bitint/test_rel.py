import pytest

from bitint import Int32


INT32_MAX = 2**31 - 1
INT32_MIN = -2**31

# eq
# Int, Int


def test_eq_pInt_pInt_true():
    assert (Int32(100) == Int32(100)) == (100 == 100)


def test_eq_pInt_pInt_false():
    assert (Int32(100) == Int32(99)) == (100 == 99)


def test_eq_mInt_mInt_true():
    assert (-Int32(100) == -Int32(100)) == (-100 == -100)


def test_eq_mInt_mInt_false():
    assert (-Int32(100) == -Int32(101)) == (-100 == -101)


def test_eq_pInt_mInt_false():
    assert (Int32(100) == -Int32(100)) == (100 == -100)


def test_eq_mInt_pInt_false():
    assert (-Int32(100) == Int32(100)) == (-100 == 100)

# Int, int


def test_eq_pInt_pint_true():
    assert (Int32(100) == 100) == (100 == 100)


def test_eq_pInt_pint_false():
    assert (Int32(100) == 99) == (100 == 99)


def test_eq_mInt_mint_true():
    assert (-Int32(100) == -100) == (-100 == -100)


def test_eq_mInt_mint_false():
    assert (-Int32(100) == -101) == (-100 == -101)


def test_eq_pInt_mint_false():
    assert (Int32(100) == -100) == (100 == -100)


def test_eq_mInt_pint_false():
    assert (-Int32(100) == 100) == (-100 == 100)


# int, Int
def test_eq_pint_pInt_true():
    assert (100 == Int32(100)) == (100 == 100)


def test_eq_pint_pInt_false():
    assert (100 == Int32(99)) == (100 == 99)


def test_eq_mint_mInt_true():
    assert (-100 == -Int32(100)) == (-100 == -100)


def test_eq_mint_mInt_false():
    assert (-100 == -Int32(101)) == (-100 == -101)


def test_eq_pint_mInt_false():
    assert (100 == -Int32(100)) == (100 == -100)


def test_eq_mint_pInt_false():
    assert (-100 == Int32(100)) == (-100 == 100)


# lt
# Int, Int


def test_lt_pInt_pInt_true():
    assert (Int32(100) < Int32(101)) == (100 < 101)


def test_lt_pInt_pInt_false():
    assert (Int32(100) < Int32(99)) == (100 < 99)


def test_lt_mInt_mInt_true():
    assert (-Int32(100) < -Int32(99)) == (-100 < -99)


def test_lt_mInt_mInt_false():
    assert (-Int32(100) < -Int32(101)) == (-100 < -101)


def test_lt_mInt_pInt():
    assert (-Int32(100) < Int32(100)) == (-100 < 100)


def test_lt_pInt_mInt():
    assert (Int32(100) < -Int32(100)) == (100 < -100)

# Int, int


def test_lt_pInt_pint_true():
    assert (Int32(100) < 101) == (100 < 101)


def test_lt_pInt_pint_false():
    assert (Int32(100) < 99) == (100 < 99)


def test_lt_mInt_mint_true():
    assert (-Int32(100) < -99) == (-100 < -99)


def test_lt_mInt_mint_false():
    assert (-Int32(100) < -101) == (-100 < -101)


def test_lt_mInt_pint():
    assert (-Int32(100) < 100) == (-100 < 100)


def test_lt_pInt_mint():
    assert (Int32(100) < -100) == (100 < -100)
# int, Int


def test_lt_pint_pInt_true():
    assert (100 < Int32(101)) == (100 < 101)


def test_lt_pint_pInt_false():
    assert (100 < Int32(99)) == (100 < 99)


def test_lt_mint_mInt_true():
    assert (-100 < -Int32(99)) == (-100 < -99)


def test_lt_mint_mInt_false():
    assert (-100 < -Int32(101)) == (-100 < -101)


def test_lt_mint_pInt():
    assert (-100 < Int32(100)) == (-100 < 100)


def test_lt_pint_mInt():
    assert (100 < -Int32(100)) == (100 < -100)

# le
# Int, Int


def test_le_pInt_pInt_true():
    assert (Int32(100) <= Int32(101)) == (100 <= 101)


def test_le_pInt_pInt_eq_true():
    assert (Int32(100) <= Int32(100)) == (100 <= 100)


def test_le_pInt_pInt_false():
    assert (Int32(100) <= Int32(99)) == (100 <= 99)


def test_le_mInt_mInt_true():
    assert (-Int32(100) <= -Int32(99)) == (-100 <= -99)


def test_le_mInt_mInt_eq_true():
    assert (-Int32(100) <= -Int32(100)) == (-100 <= -100)


def test_le_mInt_mInt_false():
    assert (-Int32(100) <= -Int32(101)) == (-100 <= -101)


def test_le_mInt_pInt():
    assert (-Int32(100) <= Int32(100)) == (-100 <= 100)


def test_le_pInt_mInt():
    assert (Int32(100) <= -Int32(100)) == (100 <= -100)

# Int, int


def test_le_pInt_pint_true():
    assert (Int32(100) <= 101) == (100 <= 101)


def test_le_pInt_pint_eq_true():
    assert (Int32(100) <= 100) == (100 <= 100)


def test_le_pInt_pint_false():
    assert (Int32(100) <= 99) == (100 <= 99)


def test_le_mInt_mint_true():
    assert (-Int32(100) <= -99) == (-100 <= -99)


def test_le_mInt_mint_eq_true():
    assert (-Int32(100) <= -100) == (-100 <= -100)


def test_le_mInt_mint_false():
    assert (-Int32(100) <= -101) == (-100 <= -101)


def test_le_mInt_pint():
    assert (-Int32(100) <= 100) == (-100 <= 100)


def test_le_pInt_mint():
    assert (Int32(100) <= -100) == (100 <= -100)

# int, Int


def test_le_pint_pInt_true():
    assert (100 <= Int32(101)) == (100 <= 101)


def test_le_pint_pInt_eq_true():
    assert (100 <= Int32(100)) == (100 <= 100)


def test_le_pint_pInt_false():
    assert (100 <= Int32(99)) == (100 <= 99)


def test_le_mint_mInt_true():
    assert (-100 <= Int32(-99)) == (-100 <= -99)


def test_le_mint_mInt_eq_true():
    assert (-100 <= -Int32(100)) == (-100 <= -100)


def test_le_mint_mInt_false():
    assert (-100 <= Int32(-101)) == (-100 <= -101)


def test_le_mint_pInt():
    assert (-100 <= Int32(100)) == (-100 <= 100)


def test_le_pint_mInt():
    assert (100 <= -Int32(100)) == (100 <= -100)

# gt
# Int, Int


def test_gt_pInt_pInt_false():
    assert (Int32(100) > Int32(101)) == (100 > 101)


def test_gt_pInt_pInt_true():
    assert (Int32(100) > Int32(99)) == (100 > 99)


def test_gt_mInt_mInt_false():
    assert (-Int32(100) > Int32(-99)) == (-100 > -99)


def test_gt_mInt_mInt_true():
    assert (-Int32(100) > Int32(-101)) == (-100 > -101)


def test_gt_mInt_pInt():
    assert (-Int32(100) > Int32(100)) == (-100 > 100)


def test_gt_pInt_mInt():
    assert (Int32(100) > -Int32(100)) == (100 > -100)

# Int, int


def test_gt_pInt_pint_false():
    assert (Int32(100) > 101) == (100 > 101)


def test_gt_pInt_pint_true():
    assert (Int32(100) > 99) == (100 > 99)


def test_gt_mInt_mint_false():
    assert (-Int32(100) > -99) == (-100 > -99)


def test_gt_mInt_mint_true():
    assert (-Int32(100) > -101) == (-100 > -101)


def test_gt_mInt_pint():
    assert (-Int32(100) > 100) == (-100 > 100)


def test_gt_pInt_mint():
    assert (Int32(100) > -100) == (100 > -100)

# int, Int


def test_gt_pint_pInt_false():
    assert (100 > Int32(101)) == (100 > 101)


def test_gt_pint_pInt_true():
    assert (100 > Int32(99)) == (100 > 99)


def test_gt_mint_mInt_false():
    assert (-100 > Int32(-99)) == (-100 > -99)


def test_gt_mint_mInt_true():
    assert (-100 > Int32(-101)) == (-100 > -101)


def test_gt_mint_pInt():
    assert (-100 > Int32(100)) == (-100 > 100)


def test_gt_pint_mInt():
    assert (100 > -Int32(100)) == (100 > -100)

# ge
# Int, Int


def test_ge_pInt_pInt_false():
    assert (Int32(100) >= Int32(101)) == (100 >= 101)


def test_ge_pInt_pInt_eq_true():
    assert (Int32(100) >= Int32(100)) == (100 >= 100)


def test_ge_pInt_pInt_true():
    assert (Int32(100) >= Int32(99)) == (100 >= 99)


def test_ge_mInt_mInt_false():
    assert (-Int32(100) >= Int32(-99)) == (-100 >= -99)


def test_ge_mInt_mInt_eq_true():
    assert (-Int32(100) >= -Int32(100)) == (-100 >= -100)


def test_ge_mInt_mInt_true():
    assert (-Int32(100) >= Int32(-101)) == (-100 >= -101)


def test_ge_mInt_pInt():
    assert (-Int32(100) >= Int32(100)) == (-100 >= 100)


def test_ge_pInt_mInt():
    assert (Int32(100) >= -Int32(100)) == (100 >= -100)

# Int, int


def test_ge_pInt_pint_false():
    assert (Int32(100) >= 101) == (100 >= 101)


def test_ge_pInt_pint_eq_true():
    assert (Int32(100) >= 100) == (100 >= 100)


def test_ge_pInt_pint_true():
    assert (Int32(100) >= 99) == (100 >= 99)


def test_ge_mInt_mint_false():
    assert (-Int32(100) >= -99) == (-100 >= -99)


def test_ge_mInt_mint_eq_true():
    assert (-Int32(100) >= -100) == (-100 >= -100)


def test_ge_mInt_mint_true():
    assert (-Int32(100) >= -101) == (-100 >= -101)


def test_ge_mInt_pint():
    assert (-Int32(100) >= 100) == (-100 >= 100)


def test_ge_pInt_mint():
    assert (Int32(100) >= -100) == (100 >= -100)
