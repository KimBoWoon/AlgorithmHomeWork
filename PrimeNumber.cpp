// 20113259 ��ǻ�Ͱ��к� 3�г� �躸��
// �˰��� ���� - �Ҽ�
#include <iostream>
#include <fstream>
using namespace std;

// �Ҽ��� �Ǻ��ϴ� �Լ�
bool primeNumber(int n);

int main() {
	ifstream in;
	int testCase = 0;

	in.open("input.txt");

	in >> testCase;

	for (int i = 0; i < testCase; i++) {
		int n = 0;

		in >> n;

		if (primeNumber(n))
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
}

bool primeNumber(int n) {
	for (int i = 2; i * i <= n; i++) {
		// ������ �������� �ռ��� �̹Ƿ� �Ҽ��� �ƴϴ�
		if (n % i == 0)
			return false;
	}
	return true;
}