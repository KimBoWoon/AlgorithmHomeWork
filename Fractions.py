__author__ = '보운'

# 20113259 컴퓨터공학부 3학년 김보운
# 알고리즘 과제 - 분수 덧셈
import fractions

with open('input.txt', 'r') as f:
    data = f.readline()

    for x in range(int(data)):
        frac = f.readline().split(' ')
        a = fractions.Fraction(int(frac[0]), int(frac[1]))
        b = fractions.Fraction(int(frac[2]), int(frac[3]))
        result = a + b

        print(result.numerator, result.denominator)
