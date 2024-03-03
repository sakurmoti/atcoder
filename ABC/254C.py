n,k = map(int, input().split())
a = list(map(int, input().split()))

b = sorted(a)
ans = True
for i in range(0, k):
    v = [a[j] for j in range(i, n, k)]
    v = sorted(v)
    for j in range(len(v)):
        if v[j] != b[i+j*k]:
            ans = False

print("Yes" if ans else "No")