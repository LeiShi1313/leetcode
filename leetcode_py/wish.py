
def print_diamond(n):
    if n % 2 == 0:
        return
    half = (n-1) / 2
    for i in range(n):
        s = ''
        spaces = abs(i-half)
        for _ in range(spaces):
            s += ' '
        for _ in range(n - 2*spaces):
            s += '*'
        print s

print_diamond(1)
print_diamond(3)
print_diamond(7)
