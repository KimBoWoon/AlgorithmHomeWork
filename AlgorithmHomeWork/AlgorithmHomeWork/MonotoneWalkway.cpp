//컴퓨터공학부 3학년 20113259
//알고리즘 과제 - MonotoneWalkway
//#include <iostream>
//#include <cstdlib>
//#include <fstream>
//#include <string.h>
//
//using namespace std;
//
//#define MAX 100001
//
//typedef struct position {
//    int x, y, n;
//} Position;
//
//int compXY(const void *x, const void *y) {
//    return ((*(Position *) x).x != (*(Position *) y).x) ?
//           (*(Position *) x).x - (*(Position *) y).x :
//           (*(Position *) x).y - (*(Position *) y).y;
//}
//
//int compN(const void *x, const void *y) {
//    return (*(Position *) x).n - (*(Position *) y).n;
//}
//
//Position pos[MAX];
//
//int main() {
//    int testCase;
//    ifstream in;
//
//    in.open("input.txt");
//
//    in >> testCase;
//
//    while (testCase--) {
//        int cafeNum, cnt;
//
//        in >> cafeNum;
//        memset(pos, 0, sizeof(Position) * MAX);
//
//        for (int i = 0; i < cafeNum; i++)
//            in >> pos[i].x >> pos[i].y;
//
//        qsort(pos, cafeNum, sizeof(Position), compXY);
//
//        int preY = 0, n = 1;
//        for (int i = 0; i < cafeNum; i++) {
//            int end = i;
//            for (int x = i + 1; x <= cafeNum; x++) {
//                if (pos[i].x == pos[x].x)
//                    end = x;
//                else
//                    break;
//            }
//            if (pos[i].y >= preY) {
//                for (int x = i; x <= end; x++)
//                    pos[x].n = n++;
//                preY = pos[end].y;
//            }
//            else {
//                for (int x = end; x >= i; x--)
//                    pos[x].n = n++;
//                preY = pos[i].y;
//            }
//            i = end;
//        }
//
//        qsort(pos, cafeNum, sizeof(Position), compN);
//		/*for (int x = 0; x < cafeNum; x++) {
//			cout << pos[x].x << " " << pos[x].y << " " << pos[x].n << endl;
//		}*/
//
//        in >> cnt;
//        for (int i = 0; i < cnt; i++) {
//            int cafe;
//            in >> cafe;
//            cout << pos[cafe - 1].x << " " << pos[cafe - 1].y << endl;
//        }
//    }
//}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 100005

int T, N, M;

struct Z{
	int x, y, o;
} A[MAXN];

bool compXY(const Z &x, const Z &y) {
	return (x.x != y.x) ?
		x.x < y.x :
		x.y < y.y;
}

bool compN(const Z &x, const Z &y) {
	return x.o < y.o;
}

int main()
{
	freopen("input.txt", "r", stdin);
	for (scanf("%d", &T); T--;){
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
			scanf("%d%d", &A[i].x, &A[i].y);
		sort(A + 1, A + N + 1, compXY);
		int last_y = 0, o = 1;
		for (int i = 1; i <= N; i++){
			int t = i;
			for (int j = i + 1; j <= N; j++){
				if (A[j].x == A[i].x) t = j;
				else break;
			}
			if (A[i].y < last_y && last_y < A[t].y)
				for (;;);
			else if (A[i].y >= last_y){
				for (int j = i; j <= t; j++)
					A[j].o = o++;
				last_y = A[t].y;
			}
			else{
				for (int j = t; j >= i; j--)
					A[j].o = o++;
				last_y = A[i].y;
			}
			i = t;
		}
		sort(A + 1, A + N + 1, compN);
		for (scanf("%d", &M); M--;){
			int n; scanf("%d", &n);
			printf("%d %d\n", A[n].x, A[n].y);
		}
	}
}