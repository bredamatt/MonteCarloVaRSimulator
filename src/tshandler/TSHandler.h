#pragma once
#include <vector>
#include "../returns/ReturnType.h"

using namespace std;

class TSHandler
{
    public:
        TSHandler(vector<vector<double>> riskFactorTimeSeries_,
                  vector<AbsOrRel> absOrRelReturnsVector_,
                  unsigned long daysBackUsed_ = 252);
        
        vector<double> GetMostRecentValues(unsigned long startDaysBack = 0) const;
        vector<vector<double>> GetReturns() const;
        void TransformToReturns();
        double ComputeCovariance(vector<vector<double>> d, int i, int j);
        void CreateCovarianceMatrix(unsigned long startingDaysBack = 0);
        vector<vector<double>> GetCovarianceMatrix() const;
        vector<vector<double>> GetPartsOfCovarianceMatrix(vector<unsigned long> diagonalIndices) const;
    
    private:
        bool transformedToReturns;
        vector<vector<double>> riskFactorTimeSeries;
        vector<AbsOrRel> absOrRelReturnsVector;
        vector<vector<double>> returns;
        vector<vector<double>> covMatrix;
        unsigned long daysBackUsed;
};
