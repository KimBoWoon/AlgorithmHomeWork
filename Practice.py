__author__ = '보운'

import Fractions

with open('input.txt', 'r') as f:
    data = f.readline();

    for x in range(int(data)):
        frac = f.readline().split(' ')
        a = Fractions.Fraction(int(frac[0]), int(frac[1]))
        b = Fractions.Fraction(int(frac[2]), int(frac[3]))
        result = a + b

        print(result.numerator, result.denominator)
