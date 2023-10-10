S = input()
S = sorted(S)
for i in range(len(S)):
    if i != int(S[i]):
        print(i)
        exit()

print(9)