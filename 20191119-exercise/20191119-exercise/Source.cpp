#include<iostream>
#include<vector>
using namespace std;

class Matrix {

public:
	int row, col, total;
	int **list;
	int count;


	Matrix(int _row, int _col):row(_row),col(_col),total(0), count(0){
		list = new int*[_row];
		for (int i = 0; i < _row; i++)
			list[i] = new int[_col];
	}
		
	friend ostream& operator<<(ostream& output, const Matrix& matrix) {
		for (int i = 0; i < matrix.row; i++) {
			for (int j = 0; j < matrix.col; j++) {
				output << matrix.list[i][j]<<" ";
			}
			output << endl;
		}
		return output;
	}

	friend istream& operator>>(istream & input, Matrix & number) {
		
		if (number.count < number.row * number.col) {
			input >> number.list[number.count / number.col][number.count % number.col];
			number.total += number.list[number.count / number.col][number.count % number.col];
			number.count++;
		}
		return input;
	}
};




int main() {
	int row, col, total;
	vector<Matrix*> list;
	Matrix* mat;
	cin >> total;
	for (int total_i = 0; total_i < total; total_i++) {
		cout << total_i << ":";
		cin >> row >> col;
		mat = new Matrix(row,col);
		for (int i = 0; i < row*col; i++)
			cin >> *mat;
		list.push_back(mat);
	}
	cout << endl;
	for (vector<Matrix*>::iterator it = list.begin(); it != list.end(); it++)
		cout << ( **it )<<endl;

	for (int i = 0; i < list.size(); i++)
		cout << "list[ " << i << " ] = " << list.at(i)->total << endl;
	system("pause");
	return 0;
}