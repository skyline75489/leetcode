def singleNumber(A):
    r = 0
    for a in A:
        r ^= a
    return r

A = [5,4,5,4,3]
print singleNumber(A)
