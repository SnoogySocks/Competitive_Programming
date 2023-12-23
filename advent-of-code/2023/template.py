import sys
from icecream import ic
from collections import deque
from dataclasses import dataclass
from typing import Tuple
import re
from tqdm import tqdm
from math import gcd


def p2():
    pass


def p1():
    pass


def main():
    assert len(sys.argv) == 3
    TEST_INPUT_STATE = sys.argv[2]
    TEST_STATE = sys.argv[1]

    if TEST_INPUT_STATE == "test":
        inps = [test, test2]
    if TEST_INPUT_STATE == "prod":
        inps = [prod]

    global arr
    for inp in inps:
        arr = [s.strip() for s in inp.split("\n")[1:-1]]
        if TEST_STATE == "p1":
            p1()
        elif TEST_STATE == "p2":
            p2()



test = """
"""

test2 = """
"""


prod = """
"""


if __name__ == "__main__":
    main()
