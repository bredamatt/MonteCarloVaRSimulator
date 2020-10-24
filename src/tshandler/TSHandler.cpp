#include "../headers/TSHandler.h"
#include <iostream>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <list>

using namespace std;

TSHandler::TSHandler(vector<vector<double>> riskFactorTimeSeries_,
                    vector<AbsOrRel> absOrRelReturnsVector_,
                    unsigned long daysBackUsed_)
{
    transformedToReturns = false;
}

vector<double> TSHandler::GetMostRecentValues(unsigned long startingDaysBack) const
{
    // define vector of size based on inner vector in riskFactorTimeSeries (this is number of elements per row, if you like)
    vector<double> mostReventValues(riskFactorTimeSeries.back().size());
    for (unsigned long j = 0; j < mostReventValues.size(); j++ )
    {
        // look startingDaysBack into riskFactorTimeSeries, subtract from time series vector final index accordingly
        mostReventValues[j] = riskFactorTimeSeries[riskFactorTimeSeries.size() - 1 - startingDaysBack][j];
    }
    return mostReventValues;
}

vector<vector<double>> TSHandler::GetReturns() const
{
    return returns;
}

void TSHandler::TransformToReturns()
{
    transformedToReturns = true;
    returns = riskFactorTimeSeries;

    // Need to subtract one element for this returns vector<vector<double>>
    returns.resize(riskFactorTimeSeries.size() -1);

    // Loop over inner vector elements (size defined by number of risk factors)
    for (unsigned long j = 0; j < riskFactorTimeSeries[1].size(); j++)
    {
        switch (absOrRelReturnsVector[j])
        {
            case AbsOrRel::abs:
                for (unsigned long i = 0; i < riskFactorTimeSeries.size() - 1; i++)
                {
                    returns[i][j] = riskFactorTimeSeries[i + 1][j] - riskFactorTimeSeries[i][j];
                }
                break;

            case AbsOrRel::rel:
                for (unsigned long i = 0; i < riskFactorTimeSeries.size() - 1; i++)
                {
                    returns[i][j] = log(riskFactorTimeSeries[i + 1][j] / riskFactorTimeSeries[i][j]);
                }
                break;
            
            default:
                break;
        }
    }
    return;
}

double TSHandler::ComputeCovariance(vector<vector<double>> d, int i, int j)
{
    /*
    Definition of Covariance:
        Covariance is simply calculate as the product of factors i and j
        divided by N, where N is number of observations

        Args:
            - d is a time indexed vector of vectors of risk factors
            - i is the first risk factor
            - j is the second risk factor
    */
    double covariance = 0;
    for (unsigned long k = 0; k < d.size(); ++k)
    {
        covariance += d[k][i] * d[k][j];
    }

    return covariance / (d.size() - 1);
}
