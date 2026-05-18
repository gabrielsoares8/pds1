#include <stdio.h>
#include <stdbool.h>

void identidade(int n, float A[][100]){
    int i = 0;
    while(i < n){
        int j = 0;
        while(j < n){
            if(i == j){
                A[i][j] = 1;
            } else {
                A[i][j] = 0;
            }
            j++;
        }
        i++;
    }
}

float media_matriz(int n, float mat[][100]){
    float soma = 0;
    int i = 0;
    while(i < n){
        int j = 0;
        while(j < n){
            soma = soma + mat[i][j];
            j++;
        }
        i++;
    }
    return soma / (n * n);
}

void transposta(int n, float A[][100], float T[][100]){
    int i = 0;
    while(i < n){
        int j = 0;
        while(j < n){
            T[j][i] = A[i][j];
            j++;
        }
        i++;
    }
}

bool simetrica(int n, float A[][100]){
    int i = 0;
    while(i < n){
        int j = 0;
        while(j < n){
            if(A[i][j] != A[j][i]){
                return false;
            }
            j++;
        }
        i++;
    }
    return true;
}

void soma_matriz(int n, float A[][100], float B[][100], float S[][100]){
    int i = 0;
    while(i < n){
        int j = 0;
        while(j < n){
            S[i][j] = A[i][j] + B[i][j];
            j++;
        }
        i++;
    }
}

void mult_matriz(int n, float A[][100], float B[][100], float P[][100]){
    int i = 0;
    while(i < n){
        int j = 0;
        while(j < n){
            P[i][j] = 0;
            int k = 0;
            while(k < n){
                P[i][j] = P[i][j] + A[i][k] * B[k][j];
                k++;
            }
            j++;
        }
        i++;
    }
}

int main(){
    int linhas, colunas;
    int matriz[10][10];

    FILE *arquivo = fopen("matriz.txt", "r");
    fscanf(arquivo, "%d %d", &linhas, &colunas);

    int i = 0;
    while (i < linhas) {
        int j = 0;
        while (j < colunas) {
            fscanf(arquivo, "%d", &matriz[i][j]);
            j++;
        }
        i++;
    }

    fclose(arquivo);

    i = 0;
    printf("1)\n");
    while (i < linhas) {
        int j = 0;
        while (j < colunas) {
            printf("%d ", matriz[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }

    float mat[100][100] = {{1,2,3},{4,5,6},{7,8,9}};
    float mat2[100][100] = {{9,8,7},{6,5,4},{3,2,1}};
    int n = 3;

    printf("\n2) %.f\n", media_matriz(n, mat));

    float identidade_mat[100][100];
    identidade(n, identidade_mat);

    printf("\n3)\n");
    int i2 = 0;
    while(i2 < n){
        int j2 = 0;
        while(j2 < n){
            printf("%.f ", identidade_mat[i2][j2]);
            j2++;
        }
        printf("\n");
        i2++;
    }

    float T[100][100];
    transposta(n, mat, T);

    printf("\n4)\n");
    int i3 = 0;
    while(i3 < n){
        int j3 = 0;
        while(j3 < n){
            printf("%.f ", T[i3][j3]);
            j3++;
        }
        printf("\n");
        i3++;
    }

    printf("\n5) ");
    if(simetrica(n, mat)){
        printf("simetrica\n");
    } else {
        printf("nao simetrica\n");
    }

    float S[100][100];
    soma_matriz(n, mat, mat2, S);

    printf("\n6)\n");
    int i4 = 0;
    while(i4 < n){
        int j4 = 0;
        while(j4 < n){
            printf("%.f ", S[i4][j4]);
            j4++;
        }
        printf("\n");
        i4++;
    }

    float P[100][100];
    mult_matriz(n, mat, mat2, P);

    printf("\n7)\n");
    int i5 = 0;
    while(i5 < n){
        int j5 = 0;
        while(j5 < n){
            printf("%.f ", P[i5][j5]);
            j5++;
        }
        printf("\n");
        i5++;
    }

    return 0;
}