
def val(c) :
    return 1 if c == "I" else -1

def minSolution(lis) :
    ans = []
    msum = 0
    csum = 0
    # Find maxsubsum on the interval
    for d in lis :
        csum += val(d)
        if csum >= val(d):
            csum = val(d)
        if csum < msum :
            msum = csum

    f = abs(msum) + 1
    ran = range(1,len(lis) + 2)
    ans.append(ran.pop(f))
    for d in lis :
        f += val(d)
        ans.append(ran.pop(f if f < len(ran) else len(ran) - 1))
    return ans



print minSolution("DDIIDI")
