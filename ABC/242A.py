A,B,C,X = map(int,input().split())

if X <= A:
    print(1)
elif A+1 <= X and X <= B:
    print(C/(B-A))
else:
    print(0)