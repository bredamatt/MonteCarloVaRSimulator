#include <iostream>
#include "tshandler/TSHandler.cpp"
#include "cholesky/CholeskyDecomposition.cpp"

using namespace std;

#define M 3
#define N 4

int main() {
    cout << "Testing CholeskyDecomposition" << endl;

    vector<vector<double>> matrix;
    matrix.resize(M, vector<double>(N, 2));

    cout << "Printing initial matrix" << endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j <= i; j++) {
            cout << matrix[i][j] << ' ';
        }
    }

    vector<vector<double>> lower = CholeskyDecomposition(matrix);

    cout << "Printing lower triangle matrix" << endl;
    for (int i = 0; i < lower.size(); i++) {
        for (int j = 0; j <= i; j++) {
            cout << lower[i][j] << ' ';
        }
    }
    return 0;
}