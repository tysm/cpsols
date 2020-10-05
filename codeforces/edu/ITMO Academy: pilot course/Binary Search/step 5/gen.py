from random import randint

n = randint(1, 20)
k = randint(0, n*n-1)
a = [randint(1, 1e9) for _ in range(n)]
b = [randint(1, 1e9) for _ in range(n)]
print(n, k)
print(" ".join(str(i) for i in a))
print(" ".join(str(i) for i in b))
