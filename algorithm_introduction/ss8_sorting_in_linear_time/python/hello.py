from array import array

arr = array('I', [3, 2, 1])
lst = list(arr)
print(arr)
print(int(''.join([str(a) for a in list(arr)])))
