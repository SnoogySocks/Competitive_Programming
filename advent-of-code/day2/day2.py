import heapq

def solve (s):
    maxs = []
    cur_sum = 0
    for line in s:
        if len(line)==0:
            heapq.heappush(maxs, cur_sum)
            if len(maxs)>3:
                heapq.heappop(maxs)
            cur_sum = 0
        else:
            cur_sum += int(line)
    print(sum(maxs))


def main ():
    with open("input.txt", "r") as f:
        solve([line.strip() for line in f.readlines()])


if __name__=="__main__":
    main()


