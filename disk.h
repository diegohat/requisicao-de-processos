#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef DISK_H
#define DISK_H

void DiskSize(char * file_name, int *disk_lines, int *disk_cols);
void DiskLoad(char *file_name, const int n_lines, const int n_cols, int matrix[n_lines][n_cols]);

#endif