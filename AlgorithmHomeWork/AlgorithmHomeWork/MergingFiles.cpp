#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
using namespace std;

int mergeMatrix[501][501] = { 0 };
int file[501] = { 0 };
int sum[501] = { 0 };

int main() {
	int testCase;

	freopen("input.txt", "r", stdin);

	cin >> testCase;

	while (testCase--) {
		int size;

		cin >> size;

		memset(mergeMatrix, 0, sizeof(int) * 501 * 501);
		memset(file, 0, sizeof(int) * 501);
		memset(sum, 0, sizeof(int) * 501);

		for (int i = 0; i < size; i++)
			cin >> file[i];
		for (int i = 0; i < size; i++)
			sum[i] = sum[i - 1] + file[i];

		int min = 0;
		for (int x = 1; x <= size; x++) {
			for (int y = 0; y <= size - x; y++) {
				int j = y + x;
				min = mergeMatrix[y][y] + mergeMatrix[y + 1][j] + sum[y] - sum[j];

				for (int k = y; k < j; k++) {
					if (min < mergeMatrix[y][k] + mergeMatrix[k + 1][j] + sum[k] - sum[j])
						min = mergeMatrix[y][k] + mergeMatrix[k + 1][j] + sum[k] - sum[j];
				}
				mergeMatrix[y][j] = min;
			}
		}
		cout << "MIN : " << min << endl;
		for (int x = 0; x <= size; x++) {
			for (int y = 0; y <= size; y++)
				cout << mergeMatrix[x][y] << " ";
			cout << endl;
		}
	}
	return 0;
}