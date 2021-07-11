#include "swap.h"

void SwapInitialize(const int n_lines, const int n_cols, int matrix[n_lines][n_cols])
{
    for(int i = 0; i < n_lines; i++)
    {
        for(int j = 0; j < n_cols; j++)
        {
            matrix[i][j] = 0;
        }
    }
}