//20113259 컴퓨터공학부 3학년 김보운
//알고리즘 과제 - Palindrome
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
using namespace std;

bool palindrome(int n) {
	for (int i = 2; i < 64; i++) {
		int temp = n;
		string result = "";

		while (temp >= i) {
			result += (temp % i) + 48;
			temp /= i;
		}
		if (temp != 0)
			result += temp + 48;

		for (int start = 0, end = result.size() - 1;; start++, end--) {
			if (result[start] != result[end])
				break;
			else if (start > end)
				return true;
		}
	}
	return false;
}

int main() {
	ifstream in;
	int testCase;

	in.open("input.txt");

	in >> testCase;

	while (testCase--) {
		int n;

		in >> n;

		if (palindrome(n))
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
}