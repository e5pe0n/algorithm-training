units = ["", "Thousand", "Million", "Biilion"]
smalls = ["Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", ]
teens = ["Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
         "Fifteen", "Sixteen", "Seventeen", "NIneteen"]
tens = ["", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
hundred = "Hundred"


def read(s: str) -> str:
    if all(map(lambda x: x == '0', s)):
        return smalls[0]
    n = (len(s) + 3 - 1) // 3
    s = '0' * (3 * n - len(s)) + s
    res = []
    idx = 0
    for i in range(n - 1, -1, -1):
        left = idx
        mid = left + 1
        right = mid + 1
        if s[left] != '0':
            res.append(smalls[int(s[left])] + " " + hundred + " ")
        if s[mid] != '0':
            if s[mid] == '1':
                res.append(teens[int(s[right])] + " ")
            else:
                res.append(tens[int(s[mid])] + " ")
        if s[right] != '0' and s[mid] != '1':
            res.append(smalls[int(s[right])] + " ")
        if s[left] != '0' or s[mid] != '0' or s[right] != '0':
            res.append(units[i] + ", ")
        idx = right + 1
    return "".join(res)[:-2]


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        s = ns(f)
    print(f"{s}: {read(s)}\n")


solve("../testcases/16_08/01.txt")
solve("../testcases/16_08/02.txt")
solve("../testcases/16_08/03.txt")
solve("../testcases/16_08/04.txt")
solve("../testcases/16_08/05.txt")
solve("../testcases/16_08/06.txt")
solve("../testcases/16_08/07.txt")


# # ../testcases/16_08/01.txt
# 1234: One Thousand, Two Hundred Thirty Four

# # ../testcases/16_08/02.txt
# 54311: Fifty Four Thousand, Three Hundred Eleven

# # ../testcases/16_08/03.txt
# 123456789: One Hundred Twenty Three Million, Four Hundred Fifty Six Thousand, Seven Hundred Eighty Nine

# # ../testcases/16_08/04.txt
# 123456789012: One Hundred Twenty Three Biilion, Four Hundred Fifty Six Million, Seven Hundred Eighty Nine Thousand, Twelve

# # ../testcases/16_08/05.txt
# 41203002001: Forty One Biilion, Two Hundred Three Million, Two Thousand, One

# # ../testcases/16_08/06.txt
# 5000000000: Five Biilion

# # ../testcases/16_08/07.txt
# 0000000: Zero
