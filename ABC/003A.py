N = int(input())
S = input()

GPA = 0
for i in S:
    if i == 'A':
        GPA += 4
    elif i == 'B':
        GPA += 3
    elif i == 'C':
        GPA += 2
    elif i == 'D':
        GPA += 1
    else:
        GPA += 0

print(GPA/N)

