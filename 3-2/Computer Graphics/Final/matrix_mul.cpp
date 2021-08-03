#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int main () {
	int rows1, cols1, rows2, cols2, i, j, k;
	double one[50][50], two[50][50], product[50][50];

	cout << "Enter Rows and Columns of First Matrix\n";
	cin >> rows1 >> cols1;

	cout << "Enter first Matrix of size " << rows1 << " X " << cols1;
	//  Input first matrix
	for (i = 0; i < rows1; i++) {
		for (j = 0; j < cols1; j++) {
			cin >> one[i][j];
		}
	}

	cout << "Enter Rows and Columns of Second Matrix\n";
	cin >> rows2 >> cols2;

	if (cols1 != rows2) {
		printf("Matrices cannot be multiplied\n");
		return 0;
	}
	//  Input second matrix
	cout << "\nEnter second Matrix of size " << rows2 << " X " << cols2;
	for (i = 0; i < rows2; i++) {
		for (j = 0; j < cols2; j++) {
			cin >> two[i][j];
		}
	}

	for (i = 0; i < rows1; i++) {
		for (j = 0; j < cols2; j++) {
			for (k = 0; k < cols1; k++) {
				product[i][j] += one[i][k] * 1.0 * two[k][j];
			}
		}
	}

	cout << "Product Matrix\n";
	for (i = 0; i < rows1; i++) {
		for (j = 0; j < cols2; j++) {
			cout << product[i][j] << " ";
		}
		cout << "\n";
	}
	main();
	return 0;
}