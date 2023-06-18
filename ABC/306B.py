input = list(map(int, input().split()))

ans = 0
cnt = 1
for i in input:
    if i == 1:
        ans += cnt * i
    cnt *= 2

print(ans)