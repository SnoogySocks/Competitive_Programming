import sys
from icecream import ic
from collections import deque
from dataclasses import dataclass
from typing import Tuple
import re


def p2():
    pass


def p1():
    pass


def main():
    assert len(sys.argv) == 2
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
"""


prod = """
"""


if __name__ == "__main__":
    main()
