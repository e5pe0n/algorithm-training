N = int(input())
S = input()
T = []
fox = list("fox")
for c in S:
    T.append(c)
    if len(T) >= 3 and T[len(T) - 3:] == fox:
        T.pop()
        T.pop()
        T.pop()
print(len(T))
