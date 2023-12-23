from pprint import pprint


def solve (s):
    sz = 14
    for i in range(sz-1, len(s)):
        st = set()
        for j in range(sz):
            st.add(s[i-j])
        if len(st)==sz:
            print(i+1)
            return


def main ():
    # solve("mjqjpqmgbljsphdztnvjfqwrcgsmlb")
    # solve("nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg")
    # solve("mjqjpqmgbljsphdztnvjfqwrcgsmlb")
    with open("input.txt", "r") as f:
        solve(f.readlines()[0])


if __name__=="__main__":
    main()

