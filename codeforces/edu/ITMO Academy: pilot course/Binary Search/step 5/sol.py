n, k = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]

c = []
for i in range(n):
    for j in range(n):
        c.append(a[i]+b[j])
c.sort()

print(c[k])
