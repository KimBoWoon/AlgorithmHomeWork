// 20113259 컴퓨터공학부 3학년 김보운
// 알고리즘 과제 - 소수
#include <iostream>
#include <fstream>
using namespace std;

// 소수를 판별하는 함수
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
		// 나누어 떨어지면 합성수 이므로 소수가 아니다
		if (n % i == 0)
			return false;
	}
	return true;
}