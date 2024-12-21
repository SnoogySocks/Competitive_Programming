import copy
import sys
from collections import defaultdict, deque
from dataclasses import dataclass
from pprint import pprint

from tqdm import tqdm


keypad = [
    "789",
    "456",
    "123",
    " 0A",
]
gamerpad = [
    " ^A",
    "<V>",
]


@dataclass(frozen=True)
class Coord:
    r: int
    c: int

    def in_bounds(self, grid):
        return 0<=self.r<len(grid) and 0<=self.c<len(grid[0])

    def add(self, coord):
        return Coord(self.r+coord.r, self.c+coord.c)

    def mul(self, scalar):
        return Coord(self.r*scalar, self.c*scalar)

    def dis(self, coord):
        return abs(self.r-coord.r) + abs(self.c-coord.c)


d = [
    Coord(-1, 0),
    Coord(1, 0),
    Coord(0, 1),
    Coord(0, -1),
]

dir_map = {
    Coord(-1, 0): "^",
    Coord(1, 0): "V",
    Coord(0, 1): ">",
    Coord(0, -1): "<",
}

dir_mapi = {
    value: key for key, value in dir_map.items()
}

dir_mapj = {
    " ": Coord(0, 0),
    "^": Coord(0, 1),
    "A": Coord(0, 2),
    "<": Coord(1, 0),
    "V": Coord(1, 1),
    ">": Coord(1, 2),
}

def main(inp):
    """
    pipeline goes you find the moves for first robot first.
    1. then you find moves for second robot
    2. then find moves for third robot
    3. then find moves for you
    """
    inp = inp.split("\n")

    def bfs(start, target, grid):
        if grid[start.r][start.c] == target:
            return []

        q = deque()
        q.append(start)
        vis = set()
        parent = dict()
        parent[start] = None
        vis.add(start)

        while q:
            cur = q.popleft()

            for dr in d:
                nxt = cur.add(dr)

                if not nxt.in_bounds(grid):
                    continue
                if grid[nxt.r][nxt.c] == " ":
                    continue
                if nxt in vis:
                    continue

                parent[nxt] = cur

                if grid[nxt.r][nxt.c] == target:
                    shortest_path = []
                    node = nxt
                    while node is not None:
                        shortest_path.append(node)
                        # print(parent)
                        node = parent[node]
                    return shortest_path[::-1]

                vis.add(nxt)
                q.append(nxt)

        assert False, "unreachable"

    def has_space(start, path, mp):
        cur = start
        for p in path:
            cur = cur.add(dir_mapi[p])
            if mp[cur.r][cur.c]==" ":
                return True
        return False

    def robot(desired, start, mp):
        row_paths = []
        for row in desired:
            s = start
            assert mp[s.r][s.c] == "A"

            cum_path = ""
            # print(row)
            for num in row:
                shortest_path = bfs(s, num, mp)

                # sort the thing based on proximity to the start node
                path = "".join(
                    sorted([dir_map[shortest_path[i].add(shortest_path[i-1].mul(-1))]
                        for i in range(1, len(shortest_path))], key=lambda x: (-dir_mapj["A"].dis(dir_mapj[x]), x)))
                assert "<>" not in path and "><" not in path and "^V" not in path and "V^" not in path
                assert mp == keypad or len(path)<=3
                assert len(set(path))<=2

                # test to see if it went through a space. If it did, then reverse path
                if has_space(s, path, mp):
                    path = path[::-1]

                # print(path)
                cum_path += path+"A"
                s = shortest_path[-1] if len(shortest_path)!=0 else s
            row_paths.append(cum_path)
            # input()

        return row_paths

    first = robot(inp, Coord(3, 2), keypad)
    second = first
    for _ in tqdm(range(25)):
        second = robot(second, Coord(0, 2), gamerpad)
    third = robot(second, Coord(0, 2), gamerpad)
    # print(first)
    # print(second)

    assert len(third) == len(inp)

    ans = 0
    for i in range(len(inp)):
        ln = len(third[i])
        numeric = int("".join([s for s in inp[i] if s.isnumeric()]))
        ans += ln*numeric
        # print(ln, numeric)
    print(ans)


test = """029A
980A
179A
456A
379A"""

test2 = """"""

prod = """789A
968A
286A
349A
170A"""

if __name__ == "__main__":
    a = sys.argv[1]
    if a == "prod":
        main(prod)
    elif a == "test":
        main(test)
    elif a == "test2":
        main(test2)
    else:
        assert False
