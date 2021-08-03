#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int main () {

	freopen("input.txt", "r", stdin);

	cout << "Enter object matrix columns: ";
	int c; cin >> c;
	cout << "Enter object matrix: ";
	double obj[50][50], product[50][50], temp[50][50], res[50][50];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < c; j++) {
			cin >> obj[i][j];
		}
	}
	cout << "Enter number of operations: ";
	int op; cin >> op;
	cout << "Enter the matrices: ";
	double operation_mat[op + 5][50][50];
	for (int i = 0; i < op; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> operation_mat[i][j][k];
			}
		}
	}

	for (int j = 0; j < 4; j++) {
		for (int k = 0; k < 4; k++) {
			temp[j][k] = operation_mat[0][j][k];
		}
	}
	if (op > 1) {
		for (int id = 1; id < op; id++) {
			memset(product, 0, sizeof product);
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					for (int k = 0; k < 4; k++) {
						product[i][j] += temp[i][k] * 1.0 * operation_mat[id][k][j];
					}
				}
			}
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					temp[j][k] = product[j][k];
				}
			}
		}
	}
	else {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				product[j][k] = temp[j][k];
			}
		}
	}



	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < c; j++) {
			for (int k = 0; k < 4; k++) {
				res[i][j] += product[i][k] * 1.0 * obj[k][j];
			}
		}
	}

	cout << "\noperation Matrix\n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << product[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\nProduct Matrix\n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < c; j++) {
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
/*
4
-1 0 1 0
0 -2 0 2
1 1 1 1
5
1 0 0
0 1 2
0 0 1

1 0 0
0 1 0
0 0 1

1 0 0
0 -1 0
0 0 1

1 0 0
0 1 0
0 0 1

1 0 0
0 1 -2
0 0 1*/