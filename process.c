#include "process.h"

void ProcessSize(char * file_name, int *process_lines, int *process_cols)
{
    FILE *pfile = fopen(file_name, "r");
    if(pfile == NULL)
    {
        perror("Disco não pode ser carregado. Erro e1");
        exit(1);
    }

    int n_lines = 1;
    
    char ptr[1024];
    const char delim[] = ", A, P, .";
    int tmp = 0;
    int n_cols = 0;

    fgets(ptr, 1024, pfile);

    while(!feof(pfile))
    {
        char *ptk = strtok(ptr, delim);
        tmp++;

        while(ptk != NULL)
        {
            ptk = strtok(NULL, delim);
            tmp++;
        }

        if(tmp > n_cols)
        {
            n_cols = tmp;
        }

        tmp = 0;
        fgets(ptr, 1024, pfile);
        n_lines++;
    }

    fclose(pfile);

    *process_lines = n_lines;
    *process_cols = n_cols + 1;
    
}

void ProcessLoad(char *file_name, const int n_lines, const int n_cols, int matrix[n_lines][n_cols])
{
    FILE *pfile= fopen(file_name, "r");
    if(pfile == NULL)
    {
        perror("Disco não pode ser carregado. Erro e2");
        exit(2);
    }
    char ptr[1024];
    const char delim[] = ", A, P, .";
    int count_lines = 0;
    int count_cols = 0;

    for(int i = 0; i < n_lines; i++)
    {
        for(int j = 0; j < n_cols; j++)
        {
            matrix[i][j] = 0;
        }
    }

    while(!feof(pfile))
    {
        fgets(ptr, 1024, pfile);
        char *ptk = strtok(ptr, delim);

        while(ptk != NULL)
        {
            matrix[count_lines][count_cols] = atoi(ptk);
            ptk = strtok(NULL, delim);
            count_cols++;
        }
        count_lines++;
        count_cols = 0;
    }
    fclose(pfile);
}