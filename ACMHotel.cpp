// 20113259 ��ǻ�Ͱ��к� 3�г� �躸��
// �˰��� ���� - ACMHotel
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main() {
	ifstream in;
	int testCase = 0;

	in.open("input.txt");

	in >> testCase;

	for (int i = 0; i < testCase; i++) {
		int height = 0, width = 0, n = 0;

		in >> height >> width >> n;
		
		double roomNum = (double)n / (double)height;
		// n�� ���̷� ������ �������� ���̸� ����ϰ� �ƴϸ� ���� �������� ����Ѵ�.�̰��� ���̵ȴ�
		(n % height == 0) ? cout << height : cout << n % height;
		// ���̸� n���� ���� ���� �ø��ϸ� ȣ���̵ȴ�.
		(roomNum < 10) ? cout << '0' << ceil(roomNum) << endl : cout << ceil(roomNum) << endl;
	}
}