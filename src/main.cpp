#include <iostream>
#include <cmath>
#include <chrono>
#include <memory>
#include <algorithm>
#include <iomanip>
#include "tshandler/TSHandler.cpp"
#include "cholesky/CholeskyDecomposition.cpp"
#include "parsers/ReadCSV.h"
#include "returns/ReturnType.h"

using namespace std;

int main() {
    string file = "data/RiskFactorsHistory.csv";

    // Parse the file and create time series
    vector<vector<double>> riskFactors = parse2DCsvFile(file);
    
    // Specify the type of returns
    vector<AbsOrRel> ReturnTypes{ AbsOrRel::rel, AbsOrRel::rel,AbsOrRel::abs, AbsOrRel::rel };

    unsigned long riskFactorDaysUsed = 250;

    TSHandler tsHandler(riskFactors, ReturnTypes, riskFactorDaysUsed);
    tsHandler.CreateCovarianceMatrix(0);

    // vector<vector<double>> covMatrix = tsHandler.GetCovarianceMatrix();
    // vector<vector<double>> lowerMatrix = CholeskyDecomposition(covMatrix);

}