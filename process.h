#include "swap.h"

#ifndef PROCESS_H
#define PROCESS_H

void ProcessSize(char * file_name, int *disk_lines, int *disk_cols);
void ProcessLoad(char *file_name, const int n_lines, const int n_cols, int matrix[n_lines][n_cols]);

#endif