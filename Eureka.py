__author__ = '김보운'


def eureka(size):
    for i in range(0, size):
        for j in range(0, size):
            for k in range(0, size):
                if (size == triangle[i] + triangle[j] + triangle[k]):
                    return True
    return False


with open('input.txt', 'r') as f:
    triangle = list()
    testCase = int(f.readline())
    for x in range(testCase):
        size = int(f.readline())
        for i in range(1, size + 1):
            triangle.append((i * (i + 1)) / 2)
        if (eureka(size)):
            print(1)
        else:
            print(0)
