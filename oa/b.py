from icecream import ic


def getMaximumPower(power):
    freq = dict()
    for i in power:
        if i not in freq:
            freq[i] = 0
        freq[i] += 1

    print(freq)
    powerr = sorted(list(freq.items()))
    n = len(powerr)

    dp = [0 for _ in range(n)]
    dp[0] = powerr[0][0]*powerr[0][1]
    for i in range(1, n):
        f1, s1 = powerr[i-1]
        f2, s2 = powerr[i]
        if f1+1!=f2:
            dp[i] = max([dp[i-1]+f2*s2, dp[i-2]+f2*s2])
        else:
            dp[i] = dp[i-2]+f2*s2

    return dp[-1]


print(getMaximumPower([3,3,3,4,4,1,8]))