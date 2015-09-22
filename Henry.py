__author__ = '보운'

# 20113259 컴퓨터공학부 3학년 김보운
# 알고리즘 과제 - Henry

from fractions import Fraction as frac

with open('input.txt', 'r') as f:
    testCase = int(f.readline())

    for x in range(testCase):
        data = f.readline().split(' ')

        henry = frac(int(data[0]), int(data[1]))

        while henry.numerator > 1:
            henry -= frac(1, int(((henry.denominator - 1) / henry.numerator + 1)))

        print(henry.denominator)