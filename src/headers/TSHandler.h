#pragma once
#include <vector>
#include "ReturnType.h"

using namespace std;

class TSHandler
{
    public:

        TSHandler(vector<vector<double>> riskFactorTimeSeries_,
                  vector<AbsOrRel> absOrRelReturnsVector_,
                  unsigned long daysBackUsed_ = 252);
        
        vector<double> GetMostRecentValues(unsigned long startDaysBack = 0) const;
        vector<double> GetReturns() const;
        void TransformToReturns();
        double ComputeCovariance(vector<vector<double>> d, int i, int j);
        void CreateCovarianceMatrix(unsigned long startingDaysBack = 0);
        vector<vector<double>> GetCovarianceMatrix() const;

        
}