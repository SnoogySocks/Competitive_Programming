from icecream import ic

def findMinimumEqualSum(rowA, rowB):
    rowAA = list(map(lambda a: a if a!=0 else 1, rowA))
    rowBB = list(map(lambda a: a if a!=0 else 1, rowB))
    sAA = sum(rowAA)
    sBB = sum(rowBB)

    if sAA==sBB:
        return sAA

    if sAA<sBB:
        if 0 in rowA:
            return sBB
        else:
            return -1

    else:
        if 0 in rowB:
            return sAA
        else:
            return -1


if __name__=="__main__":
    print(findMinimumEqualSum([1,0,2],[1,3,0,0]))