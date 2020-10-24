#include "CholeskyDecomposition.h"
using namespace std;

vector<vector<double>> CholeskyDecomposition(vector<vector<double>> matrix)
{
    // Get size
    int n = matrix.size();

    // Create inner vector with size equal to size of matrix
    vector<double> inner(n);

    // Create lower triangle matrix (square) 
    vector<vector<double>> lower(n, inner);
    
    // For i less than size of matrix, iterate over outer elements i
    for (int i = 0; i < n; i++)
    {
        // For j less than, or equal to i, iterate over inner elements j
        for (int j = 0; j <= i; j++)
        {
            double sum = 0;

            if (j == i) //for diagonal elements L(j, j)
            {
                // Move left of diagonal elements in lower triangle matrix and add values to sum
                for (int k = 0; k < j; k++)
                {
                    sum += pow(lower[j][k], 2);
                }
                // diagonal entry in the lower triangle matrix
                lower[j][j] = sqrt(matrix[j][j] - sum);
            }
            else // in scenarios L(i, j),  
            {
                // iterate left of the non-diagonal element (there should be none)
                for (int k = 0; k < j; k++)
                {
                    sum += (lower[i][k] * lower[j][k]);;
                }
                lower[i][j] = (matrix[i][j] - sum) / lower[j][j];
            }
        }
    }
    return lower;
}
