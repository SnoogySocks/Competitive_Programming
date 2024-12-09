prod = ""
test = ""


d = [(-1, 0), (0, 1), (1, 0), (0, -1)]


def main():
    """
    rotate guard to the right whenveer wall is seen and if out of bounds hten we go wooo
    """
    inp = [list(s) for s in prod.split("\n")]

    # Find guard
    guard_r = guard_c = None
    for r in range(len(inp)):
        for c in range(len(inp[0])):
            if inp[r][c] == "^":
                guard_r, guard_c = r, c

    assert guard_r is not None and guard_c is not None

    visited = set()
    v = [[0] * len(inp[0]) for _ in range(len(inp))]
    og_guard_r = guard_r
    og_guard_c = guard_c

    ans = 0

    # r and c are obstruction locations
    for r in range(len(inp)):
        for c in range(len(inp[0])):
            cur_dir = 0
            guard_r = og_guard_r
            guard_c = og_guard_c

            # loop if encountered same position in the same direction
            position = set()
            if inp[r][c] == "#":
                continue
            inp[r][c] = "#"

            flag = False

            while True:
                if (guard_r, guard_c, cur_dir) in position:
                    flag = True
                    break
                position.add((guard_r, guard_c, cur_dir))
                visited.add((guard_r, guard_c))
                v[guard_r][guard_c] = 1
                dr, dc = d[cur_dir]

                if inp[guard_r + dr][guard_c + dc] in [".", "^"]:
                    guard_r += dr
                    guard_c += dc
                elif inp[guard_r + dr][guard_c + dc] == "#":
                    cur_dir = (cur_dir + 1) % 4

                if not (
                    0 <= guard_r + dr < len(inp) and 0 <= guard_c + dc < len(inp[0])
                ):
                    break
                # pprint(v)

            if flag:
                ans += 1
            inp[r][c] = "."

    # pprint(v)
    print(ans)


test = """....#.....
.........#
..........
..#.......
.......#..
..........
.#..^.....
........#.
#.........
......#..."""

prod = """.#....#...................#................#......................#.#...............#................#....#...........#..........#
.................................#.....#............#............#.......#...#...##........#..............................#.......
..............#.#............#...............................................##.................#....................#..#.........
..............#.............................#...........................#....#....#........#.................................#..#.
............#.#..#.#...........................#.....................................#..........#............#....................
.#......................................................................#..................................#......#............#.#
...........#.............................#....................#...#.....#........#....##.........................................#
......#..##.......................................................................#............#..................................
........#.......#..........#.......#........#..................#....................#.............#.....................#.........
................#....#.##.........................#........#....#.................#...............................................
.............#........................................#....................#...............#.....#.............#...............#..
..........#.........................#...#.......................#.............................................#......#............
........#................................................#..........#.............#.............#.........#....................#..
....#............#................#.....#.#................#..................#.................#.................................
....#.........................#.............#.....#..................#....#............#...................................#......
...##....................#.............#...............................................#..........................................
.....##.......................#...................#................#..........#.....................#...................#.........
....#....#..................................................#.......................................................#.............
...#........##.........................#.......................#........#...................#...........#...................#.....
.....................##.#...................................................................#.............#.......................
........#..............#...................................................#.....................#...#.......#..#.............#...
..................................................#.......#...............#.............#........#..#.....................#.......
..#..................#...............##..................#.#.........#..........#..............#....................#..#..........
...#..................................................#...........................................#........#......................
#.................................................#..............#...#..........#....................#....................#......#
..#...#....#...........#.................................#......................................#.......................#.....#...
...#...........#..#................................#......#.............#........................##.................#....#....#...
....................#.........#.......................................................................................#...........
............................................................#................#.#..#.....#.....................#...................
.......................................#......#....................................#........................................#.....
...........#.............#...............................#..........#.........#...#.......................................#.......
.............#...............................#.#...................................................#.....#............#...........
.......................................#...#....................#.#..........##.................#...............#............#....
....................#..#....#.............#..............#....#.........................................#.##.....#................
......##..............................................................................................#...........................
....#.......#.............................#..#.........#................................#.........#...............................
..........................................................................#...............................#...........#.#.........
...............#..................................................#.........#.....................#...............#...............
.........#......#............#.........#................................#..............................##.........................
...............#.....................................#............................................#........................#......
..#...........#...........................................#.........................................................#.............
................................#......##..#............................................................................#.........
.........#...........................................#....#..............#......................##....#..#........................
.....#.............#.....#........##......................#...#..................................................#.........#..#.#.
...........................#.........#.......#..........................##...........................#..............#.............
...............................................................................#..#........................#................#.#...
.....#.#.............................................................#.........#...........#..................................#...
.....#....#..#........#....................................#......................................................................
#......................................#..#..............................#..#................#........#...........................
.....................................................................................................#.......#....#.........#.....
....#....#............................................#................................................................#..........
......#.................#.......#..............................................#...................#..............................
...................#.........................................................................................#....................
.............................#................#.#......#...#.......................................#............#............#....
...........................................................#..........#..#.................##.....#..#............................
.....#......................................................#..............................#........................#.............
...............................................#.............#........#.......................................#.......#...........
.............................................................#.............................#...........#.#...................#....
.......#......#......#......................#..................................#^.......................#.........#.......#.......
...........................................................................................................#....................#.
.....#............#.....................#....................#....................................................................
....#...........#................#.....##.............................................................#....................#......
.................................#.#....................#......................#......................#.#.................#.......
..................#......#...#..........#............#................#...#.................................................#.....
...............................................................................................................#...#.........#....
...............#.........#..............................#.......#.......#.......#.................................................
.#........#...#......................................#........#...#.......................................................#..#....
.....#...............................................................#.....#..........#.........#.....................#...........
.........................................................................................................#...#.........#......#...
.....##..................#...#.....#.........#......................................#...............................#.............
..#...............................................................................................#...............................
........#..............................#.#........#.#..#...................................................#.#....................
........................................................#........................#..#.............................................
.....................#.......................#..................................#..........................#....#.................
.........................##.........#.................................#................................#....#.....................
..#........#.......................................................................#.....#........................................
.....#.....................................#.....#....................#...............#...........................................
......................#....................................................................................................#......
...#.........................#......................................................#.......#.......#..#.....................#....
............#...#....................................................#....#......#...............#.......#......................##
.......#.................................................#...#.....................#..................#...........................
.#...................#.....#.#..............................................................................#.....................
..........#...............#......#...........#......................................................#.....#.............#...#....#
.......##.........#.....................................................#....#.........................................#.........#
..##..................#............#..#........................................#..................#..##...........................
..................#....##..............................#.....#...............#.................................................#..
........#..........#...................#.............#...............#..#........#................................................
........#..............................................##....#....................................................................
.........#.#............#.........................#..............#................................#......................#........
........#.#............................#.....#....................................................................#...............
.......................................#......................#...........................#.......................................
..........................##.....................##..#............................................................................
#.............#..............................................................................#...........#........................
......#....#.....................................#........................#.......................................................
#...................#.#.......#.......#.....................#.....#...........................................#...................
...#.......................................#............................................#................#........................
...........#.............................#........................................................................................
...............................................................#.............#..................................................#.
.........#........#....#.#..............................................#.........................................................
.........#....#....#...................#..........#............................................#..##..............................
....#...#.......................#..#....................#...#..........................##..#....#.........................#.......
....#.....##...........................#.#..............#.......................#...#.......................................#.....
......................................................................................#.#..#.....#............##....#....#........
..............#..................................................................##....#.............#............................
................##...#..............#........................#.......................#.#...#......................#...............
...#............................#...#......#.#............#........#......................#........#................#.............
..........#.....................................#.....#...............................................................#.........##
.........#.......#...................#.#.........................................................#................................
...........................#.#............................#...................#.................#.........#.......................
.....#....#.........#................................................................................#...#..................#.....
...............................#....#............................#............................................#.............#.....
......#...............#......#.........................#.#........................................................................
.......................................................................................#...................#.........#.#..#.......
.....#...................................#..................................................................#........#............
...........................................#.......................................#....................#............#...#........
....#............................#..................................#.#....#......................#....#..#.......#...#...........
.#....#................................................#..................#.......##..........................#...#...............
........#...................##...........................................................#...................................#.#..
...#..........#.#....#...................#......#................................................................#................
....#............................#....#......#..#............#..................#........#..........#....#....#........#.#........
................#....#...............#...#.#..............................................#............#................#.........
.......#.....#.#.................#......................................................................#..#......................
.#......................#.................................................#......#..........#......#....................#.........
......#.#............................#............#.......#............#.....#....................................................
.#.............#.........#..................................................#...#...........#..........#............#..#..........
...........#......#...........#............................#.......#......#......#..........#....##..#............#...............
..........................#........#.........................................................#......#........................##...
.................#....#............#...#...........................#....#....#....#...#...........................................
.............#.......................................................#.........#..................................................
....#.................................#...............#.....#....#......##..............#.......................#........#........"""

if __name__ == "__main__":
    main()
