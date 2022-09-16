camelCase = input()

numCapitalLetters = 0
for c in camelCase:
    if c.isupper():
        numCapitalLetters += 1

firstWord = 1

print(firstWord+numCapitalLetters)