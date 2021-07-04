from collections import Counter

with open("words.txt") as f:
    words = list(map(lambda x: x.strip(), list(f)))
    words = list(filter(lambda x: x != "", words))

C = Counter(words)
print(C.most_common())
