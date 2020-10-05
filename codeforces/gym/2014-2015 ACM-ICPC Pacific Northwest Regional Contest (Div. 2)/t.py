t = int(input())

def apply(op, v1, v2):
    if op == "+":
        return v1 + v2
    elif op == "-":
        return v1 - v2
    else:
        return v1 * v2

for _ in range(t):
    s = input()
    aux, c = s.split("=")
    if "*" in aux:
        a, b = aux.split("*")
        op = "*"
    elif "+" in aux:
        a, b = aux.split("+")
        op = "+"
    else:
        if "--" in aux:
            a, b = aux.split("--")
            b = "-" + b
        elif aux[0] == "-":
            _, a, b = aux.split("-")
            a = "-" + a
        else:
            a, b = aux.split("-")
        op = "-"
    ans = -1
    for i in range(10):
        d = chr(i + ord("0"))
        if d in a+b+c:
            continue
        na = a.replace("?", d)
        nb = b.replace("?", d)
        nc = c.replace("?", d)
        if str(apply(op, int(na), int(nb))) == nc:
            ans = i
            break
    print(ans)
