B = int(input())

for A in range(1,18):
    if A**A == B:
        print(A)
        exit(0)

print(-1)