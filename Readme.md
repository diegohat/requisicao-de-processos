# Algoritmo de simulação de requisição de processos
## Compile
```
make clean
make
make run
```

# Base de dados

Os arquivos de exemplo para a base de dados são utilizados os nomes "arquivos_exemplo.txt" e "processos_exemplo.txt".

Para os arquivos_exemplo, foram utilizados os separadores conforme exemplo:
```
A1, 04, 01, 08, 03, 02, 05, 07, 06
```

Para os processos_exemplo o seguinte modelo:
```
P4, A3.03, A6.05, A1.04, A2.04, A6.05, A1.04, A2.01
```

Para executar os processos, é preciso alterar o valor de PROCESS_NUMBER dentro do main.c

# Como o programa funciona

O programa recebe os valores dos arquivos do disco, tokeniza e conta os tokens + linhas do arquivo para dimensionar a matriz arquivo dinâmicamente.

O mesmo processo ocorre durante a matriz de processos com apenas uma ressalva. Os valores de PAGE (A3 ou A4) são guardados na mesma linha do processo com os valores de BLOCK (03 ou 06).

A mémoria é carregada como uma matriz de 3 linhas onde cada linha tem uma utilização.
LINHA 1: Recebe os valores de PAGE do processo;
LINHA 2: Recebe os valores de BLOCK do processo;
LINHA 3: Recebe o valor referente ao PAGE,BLOCK dentro do arquivo.

Essa matriz é inicializada com valores 0 e depois em seguida preenchida através da linha referente ao processo que é passado como parâmetro.

O preenchimento da matriz memória ocorre da seguinte maneira: Os valores impares do "vetor" processo são associados à linha 1 e os valores pares são associados à linha 2.

Existe uma verificação onde se é verificado se a posição na matriz está vazia e se ocorre a repetição de alguma solicitação dos processos. Juntamente da verificação é realizada a contagem de page miss.

Simultaneamente ocorre a remoção dos valores de dentro do disco. A remoção ocorre substituindo esses valores por -1.




