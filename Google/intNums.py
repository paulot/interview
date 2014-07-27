"""
From the set of natural integer numbers
Let x = 1234 = {1, 2, 3, 4}
Let y = 2410 = {2, 4, 1, 0}

Write an algorithm to compute the rearrangement of x that is closest to y but still greater than y. Both x and y have the same number of digits.

So in the example above, the answer would be { 2, 4, 1, 3 } = 2413 which is greater than y = 2410 and closer than any other arrangements of x.
"""

def minNum(x, y) :
    if len(x) != len (y) :
        return False
    #x.sort()
    for i, d in enumerate(x) :
        if d == y[i] :
            continue
        if d != y[i] :
            j = i
            found = False
            lis = {}
            while j < len(x) :
                if (y[i] <= x[j]) :
                    lis[j] = x[j]
                    found = True
                j += 1
            if not found :
                return False
            else:
                m = min(lis, key=lis.get)
                t = x [i]
                x[i] = lis[m]
                x[m] = t
    return x

x = [1,2,3,4]
y = [2,4,3,9]
#print minNum(x, y)
print minNum([1,2,3,4], [2,4,1,0])
print minNum([1,9,2], [2,8,1])
print minNum([1,1,1], [2,8,1])
