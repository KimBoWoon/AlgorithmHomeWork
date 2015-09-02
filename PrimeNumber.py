__author__ = 'user'

with open('input.txt', 'r') as f:
    l = f.read()
    l = l.split('\n')

def primeNumber(n):
    for x in range(2, n):
        if (n % x == 0):
            return print(0)
    return print(1)

for x in l:
    primeNumber(int(x))