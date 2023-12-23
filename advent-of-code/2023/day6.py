import sys
from icecream import ic
from collections import deque
from dataclasses import dataclass
from typing import Tuple
import re


def p2():
    # [0] - time
    # [1] - record distance
    races = [[] for _ in range(len(arr[0].split()))]
    for line in arr:
        for i, race in enumerate(line.split()):
            races[i].append(int(race))
    races = list(map(tuple, races))

    num_ways_to_win = [0]*len(races)
    for i, race in enumerate(races):
        time, record = race
        for j in range(1, time+1):
            if (time - j)*j > record:
                num_ways_to_win[i] += 1

    ic(num_ways_to_win)
    prod = 1
    for a in num_ways_to_win:
        prod *= a
    print(prod)


def p1():
    # [0] - time
    # [1] - record distance
    races = [[] for _ in range(len(arr[0].split()))]
    for line in arr:
        for i, race in enumerate(line.split()):
            races[i].append(int(race))
    races = list(map(tuple, races))

    num_ways_to_win = [0]*len(races)
    for i, race in enumerate(races):
        time, record = race
        for j in range(1, time+1):
            if (time - j)*j > record:
                num_ways_to_win[i] += 1

    ic(num_ways_to_win)
    prod = 1
    for a in num_ways_to_win:
        prod *= a
    print(prod)


def main():
    assert len(sys.argv) == 3
    TEST_INPUT_STATE = sys.argv[1]
    TEST_STATE = sys.argv[2]

    if TEST_INPUT_STATE == "test":
        inp = test
    elif TEST_INPUT_STATE == "prod":
        inp = prod

    global arr
    arr = [s.strip() for s in inp.split("\n")[1:-1]]
    if TEST_STATE == "p1":
        p1()
    elif TEST_STATE == "p2":
        p2()


test = """
71530
940200
"""


prod = """
 46828479
347152214061471
"""


if __name__ == "__main__":
    main()
