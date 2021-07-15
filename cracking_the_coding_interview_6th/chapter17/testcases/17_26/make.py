import random


fp = "03.txt"

n_docs = 100
docs_s = []
docs = []
for i in range(n_docs):
    n = int(random.uniform(1, 100))
    doc = set([int(random.uniform(0, 100000)) for _ in range(n)])
    n_words = len(doc)
    docs.append((i, n_words, doc))
    doc_s = ' '.join(map(str, doc))
    docs_s.append(f"{i} {n_words}\n{doc_s}")


res = {}
for i in range(n_docs):
    for j in range(i + 1, n_docs):
        id1, _, doc1 = docs[i]
        id2, _, doc2 = docs[j]
        intersections = len(doc1 & doc2)
        unions = len(doc1 | doc2)
        res[(id1, id2)] = intersections / unions

res = {k: v for k, v in res.items() if v != 0}
res_s = '\n'.join(map(lambda x: f"({x[0]}, {x[1]}): {res[x]}", res))

with open(fp, 'w') as f:
    docs_s = '\n'.join(docs_s)
    f.write(f"{n_docs}\n{docs_s}\n\nans:\n{res_s}")
