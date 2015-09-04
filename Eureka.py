__author__ = '김보운'

# def eureka(n):
#     x = 0
#     cnt = 1
#     while True:
#         if (n >= triangle[x]):
#             x += 1
#         else:
#             n -= triangle[x - 1]
#             cnt += 1
#             x = 0;
#
#         if (0 == n):
#             return True
#         elif (3 == cnt or n < 0):
#             return False
#
# with open('input.txt', 'r') as f:
#     triangle = list()
#     testCase = int(f.readline())
#     for x in range(testCase):
#         n = int(f.readline())
#         for i in range(1, n + 1):
#             triangle.append((i * (i + 1)) / 2)
#         if (eureka(n)):
#             print(1)
#         else:
#             print(0)

# 20113259 컴퓨터공학부 3학년 김보운
# 알고리즘 과제 - Eureka Theorem
# 삼각수를 이용하여 자연수를 구할 수 있는지 검사하는 함수
l = []
def eureka(n):
    # 리스트에 저장된 원소들을 대상으로 반복문을 돌려 검사
    for i in range(0, n):
        for j in range(0, n):
            for k in range(0, n):
                n == triangle[i] + triangle[j] + triangle[k]

    return False


with open('input.txt', 'r') as f:
    triangle = list()   # 삼각수를 저장할 리스트
    testCase = int(f.readline())
    for x in range(testCase):
        n = int(f.readline())
        # 삼각수를 구함
        for i in range(1, n + 1):
            triangle.append((i * (i + 1)) / 2)
        if (eureka(n)):
            print(1)
        else:
            print(0)
