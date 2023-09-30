import sys
sys.setrecursionlimit(10**6)


N,X = map(int, input().split())

L = list()
a = list(list())
for i in range(N):
    buf = list(map(int, input().split()))
    L.append(buf[0])
    a.append(buf[1:])

# print(L)
# print(a)

cnt = 0
def dfs(l, x):
    global cnt
    if l == N:
        if x == X:
            cnt += 1
        return
    
    for v in a[l]:
        dfs(l+1, x*v)

dfs(0,1)
print(cnt)