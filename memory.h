#include "disk.h"

#ifndef MEMORY_H
#define MEMORY_H

void MemoryInitialize(const int n_lines, const int n_cols, int matrix[n_lines][n_cols]);

void MemoryLoad(int p_count,const int m_lines, const int m_cols, int m_matrix[m_lines][m_cols], const int p_lines, const int p_cols, int p_matrix[p_lines][p_cols], const int s_lines, const int s_cols, int s_matrix[s_lines][s_cols], const int d_lines, const int d_cols, int d_matrix[d_lines][d_cols], int *pagemiss);

void MemoryFree(const int m_lines, const int m_cols, int m_matrix[m_lines][m_cols], const int s_lines, const int s_cols, int s_matrix[s_lines][s_cols], const int d_lines, const int d_cols, int d_matrix[d_lines][d_cols]);

#endif