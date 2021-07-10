def ns(f):
    return next(f).strip()


with open("02.txt") as f:
    s = f.read()

s = list(filter(lambda x: x.isalnum(), s.lower()))
s = ''.join(s)
with open("02.txt", "w") as f:
    f.write(s)
