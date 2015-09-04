// 20113259 컴퓨터공학부 3학년 김보운
// 알고리즘 과제 - ACMHotel
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
		// n을 높이로 나누어 떨어지면 높이를 출력하고 아니면 나눈 나머지를 출력한다.이것이 층이된다
		(n % height == 0) ? cout << height : cout << n % height;
		// 높이를 n으로 나눈 몫을 올림하면 호실이된다.
		(roomNum < 10) ? cout << '0' << ceil(roomNum) << endl : cout << ceil(roomNum) << endl;
	}
}