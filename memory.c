#include "memory.h"

void MemoryInitialize(const int n_lines, const int n_cols, int matrix[n_lines][n_cols])
{
    for(int i = 0; i < n_lines; i++)
    {
        for(int j = 0; j < n_cols; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

void MemoryLoad(int p_count, const int m_lines, const int m_cols, int m_matrix[m_lines][m_cols], const int p_lines, const int p_cols, int p_matrix[p_lines][p_cols], const int s_lines, const int s_cols, int s_matrix[s_lines][s_cols], const int d_lines, const int d_cols, int d_matrix[d_lines][d_cols], int *pagemiss)
{
    int pages = 0;
    int blocks = 0;
    int page_miss = 0;

    for(int i = 1; i < p_cols; i++)
    {
        for(int j = 0; j < m_cols; j++)
        {
            if(d_lines < p_matrix[p_count][i])
            {
                break;
            }
            else if((m_matrix[0][j] == p_matrix[p_count][i]) && (m_matrix[1][j] == p_matrix[p_count][i+1]))
            {
                break;
            }
            else if(m_matrix[0][pages] == 0)
            {
                if(i % 2 != 0)
                {
                    m_matrix[0][pages] = p_matrix[p_count][i];
                    m_matrix[1][blocks] = p_matrix[p_count][i+1];
                }
            }
        }
        
        if(i % 2 != 0)
        {
            pages++;
        }
        else
        {
            blocks++;
        }
    }

    for(int i = 0; i < m_cols; i++)
    {
        if((m_matrix[0][i]) != 0 && (m_matrix[1][i]) != 0)
        {
            m_matrix[2][i] = d_matrix[m_matrix[0][i]-1][m_matrix[1][i]];
            d_matrix[m_matrix[0][i]-1][m_matrix[1][i]] = 0;
            page_miss++;
        }
    }
    *pagemiss = page_miss;
}