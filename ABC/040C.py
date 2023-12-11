n = int(input())

ans = 10**9
for w in range(1, n+1):
    if (w*w > n):
        break

    h = n // w
    mod = n % w
    # print(w, h, mod)
    ans = min(ans, abs(h-w) + mod)

print(ans)
    