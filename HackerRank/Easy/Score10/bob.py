n = int(input())
arr = input().split(' ')
arr2 = []

for i in range(len(arr)):
    arr2.append(int(arr[i]))

print(sum(arr2))
