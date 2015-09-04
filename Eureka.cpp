// 20113259 컴퓨터공학부 3학년 김보운
// 알고리즘 과제 - Eureka Theorem
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// 벡터의 사이즈 만큼 반복문을 돌려서 값을 찾는다
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
		// 삼각수를 저장하기 위한 벡터
		vector<int> vec;

		in >> n;

		// n 미만의 삼각수를 구한다
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