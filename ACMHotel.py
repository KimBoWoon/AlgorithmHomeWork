__author__ = '김보운'

# 20113259 컴퓨터공학부 3학년 김보운
# 알고리즘 과제 - ACMHotel
import math

# 파일 개방
with open('input.txt', 'r') as f:
    testCase = f.readline()
    for x in range(int(testCase)):
        # 한 줄을 읽어들이고 공백을 기준으로 문자열 나눔
        data = f.readline().split(' ')
        # n을 높이로 나누어 떨어지면 높이를 출력하고 아니면 나눈 나머지를 출력한다. 이것이 층이된다
        print(data[0], end='') if int(data[2]) % int(data[0]) == 0 else print(int(data[2]) % int(data[0]), end='')
        # 높이를 n으로 나눈 몫을 올림하면 호실이된다.
        print('{0}{1}'.format(0, math.ceil(float(data[2]) / float(data[0])))) if float(data[2]) / float(data[0]) < 10 else print(math.ceil(float(data[2]) / float(data[0])))
