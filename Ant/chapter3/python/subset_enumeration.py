sup = int("01101101", 2)
sub = sup
# do something for sub
sub = (sub - 1) & sup
while sub != sup:
    # do something for sub
    print(f"{sub:08b}")
    sub = (sub - 1) & sup

# 01101100
# 01101001
# 01101000
# 01100101
# 01100100
# 01100001
# 01100000
# 01001101
# 01001100
# 01001001
# 01001000
# 01000101
# 01000100
# 01000001
# 01000000
# 00101101
# 00101100
# 00101001
# 00101000
# 00100101
# 00100100
# 00100001
# 00100000
# 00001101
# 00001100
# 00001001
# 00001000
# 00000101
# 00000100
# 00000001
# 00000000