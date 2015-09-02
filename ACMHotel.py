__author__ = '김보운'

import math

with open('input.txt', 'r') as f:
    testCase = f.readline()
    for x in range(int(testCase)):
        data = f.readline().split(' ')
        print(data[0], end='') if int(data[2]) % int(data[0]) == 0 else print(int(data[2]) % int(data[0]), end='')
        print('{0}{1}'.format(0, math.ceil(float(data[2]) / float(data[0])))) if float(data[2]) / float(data[0]) < 10 else print(math.ceil(float(data[2]) / float(data[0])))
