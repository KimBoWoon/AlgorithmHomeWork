#include <iostream>
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

		(n % height == 0) ? cout << height : cout << n % height;
		(roomNum < 10) ? cout << '0' << ceil(roomNum) << endl : cout << ceil(roomNum) << endl;
	}
}