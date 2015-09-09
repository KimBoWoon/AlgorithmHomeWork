//20113259 컴퓨터공학부 3학년 김보운
//알고리즘 과제 - 되부름을 이용한 팩토리얼 계산
#include <iostream>
#include <fstream>
using namespace std;

int fact(int n);

int main() {
	ifstream in;
	int testCase;

	in.open("input.txt");

	in >> testCase;

	for (int i = 0; i < testCase; i++) {
		int n = 0;

		in >> n;

		cout << fact(n) << endl;
	}
}

int fact(int n) {
	if (n == 0)
		return 1;
	else
		return n * fact(n - 1);
}