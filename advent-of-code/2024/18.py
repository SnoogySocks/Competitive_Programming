import sys


def main(inp):
    pass


test = """"""

test2 = """"""

prod = """"""

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
