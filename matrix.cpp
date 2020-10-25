#include <vector>
#include "src/cholesky/CholeskyDecomposition.cpp"

#define MAXROWS 10
#define MAXCOLS 10

double ComputeCovariance(vector<vector<double>> d, int i, int j)
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
    return (covariance / (d.size() - 1));
}

int main()
{
    vector<vector<double>> matrix(10, vector<double>(10, 0));
    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[i].size(); j++)
            matrix[i][j] = rand() % 10 + 1;

    cout << "Printing initial matrix" << endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.back().size(); j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }

    // Testing Covariance Matrix
    cout << "Testing Cov Matrix" << endl;
    int startBack = 0;
    int daysBackUsed = 3;
    vector<vector<double>>::const_iterator first = matrix.end() - startBack - daysBackUsed;
    vector<vector<double>>::const_iterator last = matrix.end() - startBack;
    vector<vector<double>> reSizedReturns(first, last);
    vector<vector<double>> covMatrix;

    int dimensions = reSizedReturns.back().size();
    covMatrix.resize(dimensions);

    for (int i = 0; i < dimensions; ++i) 
    {
        covMatrix[i].resize(dimensions);
        for (int j = i; j < dimensions; ++j)
        {
            covMatrix[i][j] = ComputeCovariance(reSizedReturns, i, j) * daysBackUsed; // scale by daysBackUsed
        }
    }
    for (int i = 1; i < dimensions; i++)
    {
        for (int j = 0; j < i; ++j)
        {
            covMatrix[i][j] = covMatrix[j][i];
        }
    }

    cout << "Printing CovMatrix" << endl;
    for (int i = 0; i < covMatrix.size(); i++) {
        for (int j = 0; j < covMatrix.back().size(); j++) {
            cout << covMatrix[i][j] << ' ';
        }
        cout << endl;
    }

    // Testing  Cholesky
    cout << "Testing CholeskyDecomposition" << endl;
    vector<vector<double>> lower = CholeskyDecomposition(covMatrix);
    cout << "Printing lower triangle matrix" << endl;
    for (int i = 0; i < lower.size(); i++) {
        for (int j = 0; j < lower.back().size(); j++) {
            cout << lower[i][j] << ' ';
        }
        cout << endl;
    }
}