#include <iostream>
#include "tshandler/TSHandler.cpp"
#include "cholesky/CholeskyDecomposition.cpp"
#include "parsers/ReadCSV.cpp"

using namespace std;

#define M 3
#define N 4

int main() {
    string file = "data/RiskFactorsHistory.csv";
    vector<vector<double>> riskFactors = parse2DCsvFile(file);
    vector<AbsOrRel> absOrRelVec;

    TSHandler tsHandler(riskFactors, absOrRelVec);

    // vector<double> rets = tsHandler.GetMostRecentValues();
    tsHandler.TransformToReturns();

    // vector<vector<double>> covMatrix = tsHandler.GetCovarianceMatrix();
    // vector<vector<double>> lowerMatrix = CholeskyDecomposition(covMatrix);

    // Testing Cholesky Decomposition
    cout << "Testing CholeskyDecomposition" << endl;
    vector<vector<double>> matrix;
    matrix.resize(M, vector<double>(N, 2));
    cout << "Printing initial matrix" << endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j <= i; j++) {
            cout << matrix[i][j] << ' ';
        }
    }
    cout << endl;
    vector<vector<double>> lower = CholeskyDecomposition(matrix);
    cout << "Printing lower triangle matrix" << endl;
    for (int i = 0; i < lower.size(); i++) {
        for (int j = 0; j <= i; j++) {
            cout << lower[i][j] << ' ';
        }
    }
    cout << endl;
    return 0;
}