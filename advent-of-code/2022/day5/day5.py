from pprint import pprint

width = 9
start = 10

def solve (s):
    # parse the crates
    col = 1
    crates = {}
    for i in range(1, width+1):
        stack = ""
        for j in range(start-2):
            stack += s[j][col]

        crates[i] = list(stack.strip())[::-1]
        col += 4

    moves = parse_input(s)
    for move in moves:
        (n, from_, to) = move
        crates[to] += crates[from_][-n:]
        crates[from_] = crates[from_][:-n]

    pprint(crates)
    for _, v in sorted(crates.items()):
        print(0 if len(v)==0 else v[-1], end='');


def parse_input (s) -> list[tuple[int, ...]]:
    moves = []
    # input starts on line 12
    for i in range(start, len(s)):
        move = s[i].split()
        moves.append(tuple(map(int, (move[1], move[3], move[5]))))
    return moves


def main ():
    with open("input.txt", "r") as f:
        solve([line for line in f.readlines()])


if __name__=="__main__":
    main()

