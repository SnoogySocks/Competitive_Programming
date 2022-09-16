# https://www.hackerrank.com/challenges/mark-and-toys/problem

n_k = input().split()
n, allowance = int(n_k[0]), int(n_k[1])

arr = []
for num_str in input().split():
    arr.append(int(num_str))

arr.sort()

count = 0
for price in arr:
    if allowance-price>=0:
        allowance -= price
        count += 1
    else:
        break

print(count)
