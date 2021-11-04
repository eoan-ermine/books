def phi(n):
    phi = n
    for p in range(2, int(n ** 0.5) + 1):
        if not n % p:
            phi -= phi // p
            while not n % p:
                n //= p
    if n > 1:
        phi -= phi // n
    return phi

k = int(input())
flag = False
for n in range(15000):
    b = phi(n)
    if b != 0 and k / phi(n) == n:
        print(n)
        flag = True
        break
if not flag:
    print("NO")