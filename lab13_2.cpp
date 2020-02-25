#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

// Write definition of inputMatrix(),matrixMultiply() and showMatrix() here

void inputMatrix(double x[N][N]){
	for(int i=0; i<N; i++){
		cout << "Row" << i+1 << ":";
		for(int j=0; j<N; j++) cin >> x[i][j];
	}
}

void findLocalMax(const double x[N][N], bool y[N][N]){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(i==0||i==4||j==0||j==4) y[i][j] = 0;
			else{
				if(x[i][j] > x[i][j-1]&&x[i][j] > x[i][j+1]&&x[i][j] > x[i-1][j]&&x[i][j] > x[i+1][j]){
					y[i][j]=1;
				}else{
					y[i][j]=0;
				}
			}
		}
	}
}

void showMatrix(const bool x[N][N]){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++) cout << x[i][j] << " ";
		cout << "\n";
	}
}