#include "process.h"
#define MEM_SIZE 5
#define SWAP_SIZE 10
#define SIZE 3
#define PROCESS_NUMBER 3

int main(void)
{
    int disk_lines = 0;
    int disk_cols = 0;
    int process_lines = 0;
    int process_cols = 0;
    int pagemiss = 0;

    DiskSize("arquivos_exemplo.txt", &disk_lines, &disk_cols);

    int m_disk[disk_lines][disk_cols];
    
    DiskLoad("arquivos_exemplo.txt", disk_lines, disk_cols, m_disk);

    ProcessSize("processos_exemplo.txt", &process_lines, &process_cols);
    
    int m_process[process_lines][process_cols];

    ProcessLoad("processos_exemplo.txt", process_lines, process_cols, m_process);

    int m_memory[SIZE][MEM_SIZE];

    MemoryInitialize(SIZE, MEM_SIZE, m_memory);

    int m_swap[SIZE][SWAP_SIZE];

    SwapInitialize(SIZE, SWAP_SIZE, m_swap);

    MemoryLoad(PROCESS_NUMBER, SIZE, MEM_SIZE, m_memory, process_lines, process_cols, m_process, SIZE, SWAP_SIZE, m_swap, disk_lines, disk_cols, m_disk, &pagemiss);

    printf("\nDISCO:\n\n");

    for(int i = 0; i < disk_lines; i++)
    {
        for(int j = 0; j < disk_cols; j++)
        {
            printf("%i\t", m_disk[i][j]);
        }
        printf("\n");
    }

    printf("\n\nMEMÓRIA INICIALIZADA:\n\n");

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < MEM_SIZE; j++)
        {
            printf("%i\t", m_memory[i][j]);
        }
        printf("\n");
    }

    printf("PAGEMISS: %i\n", pagemiss);


    MemoryFree(SIZE, MEM_SIZE, m_memory, SIZE, SWAP_SIZE, m_swap, disk_lines, disk_cols, m_disk);

    printf("\nDISCO:\n\n");

    for(int i = 0; i < disk_lines; i++)
    {
        for(int j = 0; j < disk_cols; j++)
        {
            printf("%i\t", m_disk[i][j]);
        }
        printf("\n");
    }

    printf("\n\nMEMÓRIA INICIALIZADA:\n\n");

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < MEM_SIZE; j++)
        {
            printf("%i\t", m_memory[i][j]);
        }
        printf("\n");
    }
}