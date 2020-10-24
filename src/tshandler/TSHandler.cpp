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
        Covariance is simply calculate as:
        the product of risk factors i and j divided by N-1,
        where N is number of observations (size of outer vector)

        Args:
            - d is the outer vector (vector<vector<T>>)
            - i is the first risk factor value
            - j is the second risk factor value
    */
    double covariance = 0;
    for (unsigned long t = 0; t < d.size(); ++t)
    {
        // For each time period t, add product i*j to sum 
        covariance += d[t][i] * d[t][j];
    }
    // Divide sum by N-1
    return covariance / (d.size() - 1);
}

vector<vector<double>> TSHandler::CreateCovarianceMatrix(unsigned long startingDaysBack) 
{
    if (!transformedToReturns)
        TransformToReturns();
    
    if (returns.size() < (daysBackUsed + startingDaysBack))
    {
        daysBackUsed = returns.size() - startingDaysBack;
        cout << "Warning: short time series. Only using " << daysBackUsed << " number of days back. \n \n";
    }

    vector<vector<double>>::const_iterator first = returns.end() - startingDaysBack - daysBackUsed;
    vector<vector<double>>::const_iterator last = returns.end() - startingDaysBack;
}