from icecream import ic
from collections import deque
import heapq as hq
from dataclasses import dataclass
from typing import Tuple
import re


# INPUT_STATE = "TEST"
INPUT_STATE = "PROD"


def p2():
    pass


def p1():
    pass


def main():
    if INPUT_STATE == "TEST":
        inp = test
    elif INPUT_STATE == "PROD":
        inp = prod

    global arr
    arr = [s.strip() for s in inp.split("\n")[1:-1]]
    # p1()
    p2()


test = """
"""


prod = """
"""


if __name__ == "__main__":
    main()
