n, ans = int(input()), 0
for i in range(1, n+1):
    s = str(i)
    for c in s:
        if int(c) in {1, 7}:
            ans += 1
print(ans)
