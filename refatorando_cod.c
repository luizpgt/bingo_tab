#include <stdlib.h>
#include <stdio.h>

int printCabecalho() {//funcao responsável por exibir o cabecalho
    char cabecalho[5] = "BINGO";
    int j;
    for (j = 0; j < 5; j++){
        printf ("%c       ", cabecalho[j]);
    }
    printf ("\n");
}

int existe(int **cartela, int num) {//FUNCAO - verifica a existencia de um numero repetido na matriz, e o evita
    int q, w;
        for(q = 0; q < 5; q++) {
            for(w = 0; w < 5; w++) {
                if(cartela[q][w] == num) {
                return 1;
                }
            }
        }
    return 0;
}

int printMatriz(int **cartela) {//FUNCAO - exibe a matriz ao finalizar as operacoes
    int y, u;
    for(y = 0; y < 5; y++) {
        for(u = 0; u < 5; u++) {
            if(y == 2 && u == 2) {
                printf ("*       ");
            } else {
                printf ("%02d      ", cartela[y][u]);
            }

        }
        printf("\n");
    }
}

int montarFicha() {
    int **cartela;
    cartela = malloc(5 * sizeof(int *));
        for (int i = 0; i < 5; ++i){
            cartela[i] = malloc (5 * sizeof(int));
        }
    int size = 25; //tamanho da matriz (25 posicões)
    int lin = 0, col = 0; //linhas e colunas da matriz
    int cont = 0; //contador para as 25 posicões da matriz
    int num; //numero específico que será entrado na matriz

    while(cont < size) {
            //corrente de if's responsável por delimitar os números de cada coluna
            //uso da funcao rand()
            if(col == 0) {
                 num = 1 + rand() % (15-1+1);
            }            if(col == 1) {
                 num = 16 + rand() % (30-16+1);
            }            if(col == 2) {
                 num = 31 + rand() % (45-31+1);
            }            if(col == 3) {
                 num = 46 + rand() % (60-46+1);
            }            if(col == 4) {
                 num = 61 + rand() % (75-61+1);
            }

        if(existe(cartela, num) == 0) {
                cartela[lin][col] = num;
                cont++;
            //contador linha-coluna
            if(col >= 4) {
                col = -1;
                lin++;
            }
            col++;
            //contador linha-coluna
        }
    }
    printMatriz(cartela);
    printf ("\n\n");


}

int main() {
    int n; //numero de cartelas - entrada do usuario
    printf("Informe o numero de cartelas a serem processadas: ");
    scanf ("%d", &n);
    printf ("\n\n");

    for(int c = 0; c < n; c++) {
        printCabecalho();
        montarFicha();
   }
}
