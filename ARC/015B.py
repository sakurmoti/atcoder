N = int(input())

ans = [0]*6
for i in range(N):
    M,m = list(map(float, input().split()))

    if M >= 35:
        ans[0] += 1
    if M >= 30 and M < 35:
        ans[1] += 1
    if M >= 25 and M < 30:
        ans[2] += 1
    if m >= 25:
        ans[3] += 1
    if m < 0 and M >= 0:
        ans[4] += 1
    if M < 0:
        ans[5] += 1

print(*ans)

