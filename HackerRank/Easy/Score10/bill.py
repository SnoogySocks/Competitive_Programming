n = int(input())
strings = []
for i in range(n):
    strings.append(input())

m = int(input())
queries = []
for i in range(m):
    queries.append(input())

for query in queries:
    count = 0
    for string in strings:
        if query==string:
            count += 1
    print(count)
