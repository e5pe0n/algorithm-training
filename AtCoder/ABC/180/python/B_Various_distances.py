N = int(input())
X = map(int, input().split())

md = 0
ed = 0.0
cd = 0
for x in X:
    md += abs(x)
    ed += x * x
    cd = max(cd, abs(x))
ed **= 0.5
print(md)
print(f"{ed:.10f}")
print(cd)
