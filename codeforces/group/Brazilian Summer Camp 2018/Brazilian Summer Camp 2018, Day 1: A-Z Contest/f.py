n, k = (int(i) for i in input().split())

fib = [0]*(n+2)
fib[0], fib[1] = 0, 1
for i in range(2, n+2):
    fib[i] = fib[i-1] + fib[i-2]

if n == 1:
    if k == 1:
        print("0")
    else:
        print("1")
else:
    ans = ""
    for i in reversed(range(1, n+1)):
        if k > fib[1+i]:
            ans += "1"
            k -= fib[1+i]
        else:
            ans += "0"
    print(ans)

