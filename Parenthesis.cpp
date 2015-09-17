// 20113259 ��ǻ�Ͱ��к� 3�г� �躸��
// �˰��� ���� - Parenthesis
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int parenthesis(string par, int begin);

int main() {
	ifstream in;
	int testCase;

	in.open("input.txt");

	in >> testCase;

	for (int i = 0; i < testCase; i++) {
		string par;

		in >> par;

		if (parenthesis(par, 0) != 0)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}

int parenthesis(string par, int begin) {
	int cnt = 0;

	if (begin < par.size() - 1)
		cnt = parenthesis(par, begin + 1);

	if (par[begin] == '(')
		return ++cnt;
	else if (par[begin] == ')')
		return --cnt;

	return cnt;
}