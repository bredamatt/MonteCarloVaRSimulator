#include <iostream>
#include "tshandler/TSHandler.cpp"
#include "cholesky/CholeskyDecomposition.cpp"
#include "parsers/ReadCSV.cpp"
#include "returns/ReturnType.h"

using namespace std;


int main() {
    string file = "data/RiskFactorsHistory.csv";
    vector<vector<double>> riskFactors = parse2DCsvFile(file);
    vector<AbsOrRel> absOrRelVec(riskFactors.back().size());
    TSHandler tsHandler(riskFactors, absOrRelVec);

    // vector<double> rets = tsHandler.GetMostRecentValues();
    // tsHandler.TransformToReturns();
    // vector<vector<double>> covMatrix = tsHandler.GetCovarianceMatrix();
    // vector<vector<double>> lowerMatrix = CholeskyDecomposition(covMatrix);

    // Test matrix (3x3) where each (i,j) = 2
    vector<vector<double>> matrix;
    vector<double> inner(3, 2);
    matrix.resize(3, inner);

    // Testing Covariance Matrix
    cout << "Testing Cov Matrix" << endl;
    vector<vector<double>>::const_iterator first = matrix.end() - 0 - 1;
    vector<vector<double>>::const_iterator last = matrix.end() - 0;
    vector<vector<double>> reSizedReturns(first, last);
    vector<vector<double>> covMatrix;

    int dimensions = reSizedReturns.back().size();
    covMatrix.resize(dimensions);

    cout << "Printing CovMatrix" << endl;
    for (int i = 0; i < covMatrix.size(); i++) {
        for (int j = 0; j < covMatrix.back().size(); j++) {
            cout << covMatrix[i][j] << ' ';
        }
        cout << endl;
    }

    // Testing  Cholesky
    cout << "Testing CholeskyDecomposition" << endl;
    cout << "Printing initial matrix" << endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.back().size(); j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }

    vector<vector<double>> lower = CholeskyDecomposition(matrix);
    cout << "Printing lower triangle matrix" << endl;
    for (int i = 0; i < lower.size(); i++) {
        for (int j = 0; j < lower.back().size(); j++) {
            cout << lower[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}