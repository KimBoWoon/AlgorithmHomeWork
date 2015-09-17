// 20113259 ��ǻ�Ͱ��к� 3�г� �躸��
// �˰����� ���� - Eureka Theorem
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// ������ ������ ��ŭ �ݺ����� ������ ���� ã�´�
bool eureka(vector<int> vec, int n) {
	for (int x = 0; x < vec.size(); x++) {
		for (int y = 0; y < vec.size(); y++) {
			for (int z = 0; z < vec.size(); z++) {
				if (vec[x] + vec[y] + vec[z] == n)
					return true;
			}
		}
	}
	return false;
}
int main() {
	ifstream in;
	int testCase = 0;

	in.open("input.txt");

	in >> testCase;

	for (int i = 0; i < testCase; i++) {
		int n = 0;
		// �ﰢ���� �����ϱ� ���� ����
		vector<int> vec;

		in >> n;

		// n �̸��� �ﰢ���� ���Ѵ�
		for (int x = 1; x < n; x++) {
			if ((x * (x + 1)) / 2 >= n)
				break;
			else
				vec.push_back((x * (x + 1)) / 2);
		}
		if (eureka(vec, n))
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
}