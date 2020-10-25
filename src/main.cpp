#include <iostream>
#include "tshandler/TSHandler.cpp"
#include "cholesky/CholeskyDecomposition.cpp"
#include "parsers/ReadCSV.cpp"
#include "returns/ReturnType.h"

using namespace std;

int main() {
    string file = "data/RiskFactorsHistory.csv";
    vector<vector<double>> riskFactors = parse2DCsvFile(file);
    cout << "Size of risk factors matrix: " << riskFactors.size() << endl;

    vector<AbsOrRel> absOrRelVec(riskFactors.size());
    TSHandler tsHandler(riskFactors, absOrRelVec);

    /**
     * Need to look into enum case handling 
     * Methods work, just need to check matrix.cpp to validate
     * */

    // tsHandler.TransformToReturns();
    // vector<vector<double>> covMatrix = tsHandler.GetCovarianceMatrix();
    // vector<vector<double>> lowerMatrix = CholeskyDecomposition(covMatrix);


    return 0;
}