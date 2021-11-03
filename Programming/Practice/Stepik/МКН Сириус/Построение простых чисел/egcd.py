def gcd(a, b):
    d, x, y = 0, 0, 0
    if b == 0:
        d, x, y = a, 1, 0
    else:
        d, x, y = gcd(b, a % b)
        x, y = y, x - (a // b) * y
    return d, x, y

a, m = map(int, input().split())
_, x, _ = gcd(a, m)
print(x % m)