import sys


def get_output(A, B, C, program):
    i = 0
    ans = []
    while i < len(program):
        combo_operand = None
        assert 0 <= program[i + 1] <= 6
        if 0 <= program[i + 1] <= 3:
            combo_operand = program[i + 1]
        elif program[i + 1] == 4:
            combo_operand = A
        elif program[i + 1] == 5:
            combo_operand = B
        elif program[i + 1] == 6:
            combo_operand = C

        assert 0 <= program[i] <= 7
        # perform adv
        if program[i] == 0:
            A = A // (1 << combo_operand)
        elif program[i] == 1:
            B = B ^ program[i + 1]
        elif program[i] == 2:
            B = combo_operand % 8
        elif program[i] == 3:
            if A == 0:
                i += 2
                continue
            i = program[i + 1]
            continue
        elif program[i] == 4:
            B = B ^ C
        elif program[i] == 5:
            ans.append(combo_operand % 8)
        elif program[i] == 6:
            B = A // (1 << combo_operand)
        elif program[i] == 7:
            C = A // (1 << combo_operand)

        i += 2

    return ans


def main(inp):
    """
    A = ASTUXYZ
    A010 ^ 101 == (XYZ) ^ (APQRSTUXYZ >> 7)
    A111 == (XYZ) ^ (ASTU)
    XYZ = 111
    STU = 000

    So really just want to remember the last 7 numbers.
    Find all possible 7 bit numbers that can create the first number
    in the program. This will be a possibility set

    next find all possible 10 bit numbers that can create the first and
    second number in the program from the possibility set. Make sure
    that bit length is a multiple of 2

    end when reached the required bit length
    """
    inp = inp.split("\n")
    og_A = int(inp[0].split()[2])
    B = int(inp[1].split()[2])
    C = int(inp[2].split()[2])

    program = [int(a) for a in inp[4].split()[1].split(",")]
    assert len(program) % 2 == 0

    # find all 7 digit numbers that give program[0]
    possibilities = set()
    for A in range(1 << 8):
        a = get_output(A, B, C, program)
        if len(a) != 0 and a[0] == program[0]:
            possibilities.add(A)

    possibilities_nxt = set()
    # used 7 bits, so have len(program)*3 bits to go
    flag = False
    for i in range(1, len(program)):
        """
        at 3, so iterate through to 10 bits
        know that possibilities already found numbers within 7 bit range
        so only have to iterate for 3 bits here
        since we are appending the iterated 3 bits onto the 7 bit number
        and then checking to see whether the output matches the program's
        second number
        """
        for possibility in possibilities:
            if len(bin(possibility + (7 << i * 3 + 5))) - 2 > len(program) * 3 + 6:
                flag = True
                break
            for j in range(1 << 3):
                A = possibility + (j << i * 3 + 5)
                a = get_output(A, 0, 0, program)
                if len(a) > i and a[i] == program[i]:
                    possibilities_nxt.add(A)

        if flag:
            break

        possibilities = possibilities_nxt
        possibilities_nxt = set()

        # exit when there's a number A that has bits larger than program
        # length

    # print(possibilities)
    print(get_output(min(possibilities), 0, 0, program))
    print(min(possibilities))


test = """Register A: 729
Register B: 0
Register C: 0

Program: 0,1,5,4,3,0"""

test2 = """Register A: 2024
Register B: 0
Register C: 0

Program: 0,3,5,4,3,0"""

prod = """Register A: 28066687
Register B: 0
Register C: 0

Program: 2,4,1,1,7,5,4,6,0,3,1,4,5,5,3,0"""

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
