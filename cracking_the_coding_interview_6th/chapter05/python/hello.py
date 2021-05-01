from bitint import Int32


print(Int32(-1) < Int32(5))
print(Int32(-1) < 5)
print(-1 < Int32(5))

print(Int32(-1) < 5.0)
print(-1.0 < Int32(5))
