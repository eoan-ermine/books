def phi(n):
    result = n
    for i in range(2, n):
        if n % i == 0:
            while n % i == 0:
                n /= i
            result = result - (result / i)
    if n > 1:
        result -= result / n
    return int(result)

a, m = map(int, input().split())
print(phi(m), (a ** (phi(m) - 1)) % m)