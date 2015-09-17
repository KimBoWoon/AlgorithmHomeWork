//20113259 ��ǻ�Ͱ��к� 3�г� �躸��
//�˰����� ���� - �Ǻθ��� �̿��� �м��� ����
#include <iostream>
#include <fstream>
using namespace std;

int euclid(int x, int y);

int main() {
	ifstream in;
	int testCase;

	in.open("input.txt");

	in >> testCase;

	for (int i = 0; i < testCase; i++) {
		int x, y, n, m;
		int den = 0, num = 0, gcd = 0;

		in >> x >> y >> n >> m;

		if (y != m) {
			den = y * m;
			num = (x * m) + (y * n);
		}
		else {
			den = y;
			num = x + n;
		}

		gcd = euclid(num, den);
		cout << num / gcd << ' ' << den / gcd << endl;
	}
}
int euclid(int x, int y) {
	if (y == 0)
		return x;
	else
		return euclid(y, x % y);
}