from decimal import *

getcontext().prec = 150  # floating precision.

# .150 PI.
PI = Decimal("3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128")

def cos(x):
    getcontext().prec += 2
    i, lasts, s, fact, num, sign = 0, 0, 1, 1, 1, 1
    while s != lasts:
        lasts = s
        i += 2
        fact *= i * (i-1)
        num *= x * x
        sign *= -1
        s += num / fact * sign
    getcontext().prec -= 2
    return +s

def sec(x):
    return 1/cos(x)

def sin(x):
    getcontext().prec += 2
    i, lasts, s, fact, num, sign = 1, 0, x, 1, x, 1
    while s != lasts:
        lasts = s
        i += 2
        fact *= i * (i-1)
        num *= x * x
        sign *= -1
        s += num / fact * sign
    getcontext().prec -= 2
    return +s

def csc(x):
    return 1/sin(x)
     
def atan(x):
    getcontext().prec += 2
    s, last, numer, i = x, -2, x, 0
    while s != last:
        last = s
        i = i + 1
        numer *= x * x * -1
        s += numer / (2 * i + 1)
    getcontext().prec -= 2
    return +s

with open("gsm.in", "r") as f:
    l, r = map(Decimal, f.read().split())

fout = open("gsm.out", "w")

c_area = PI * r**2 # circle
h_area = l**2 * Decimal(3).sqrt() * 3 / 2 # hexagon

if 4*r**2 <= 3*l**2:
    print(str(c_area/h_area), file=fout)
elif r >= l:
    print(1, file=fout)
else:
    sqCosA = (l/r)**2 * 3/4
    a = atan((1/sqCosA - 1).sqrt())
    s_area = a * r**2 # sector with ang 2*a

    moon = 6*s_area - 3*r*r*sin(2*a)
    print(str((c_area - moon)/h_area), file=fout)
