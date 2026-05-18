#include <stdio.h>
#include <math.h>

float media(float v[], int n){
    int i = 0;
    float soma = 0;
    while(i < n){
        soma = soma + v[i];
        i++;
    }
    return soma / n;

}

float variancia(float v[], int n){
    float med = media(v, n);
    float soma = 0;
    int i = 0;

    while (i < n){
        soma = soma + pow((v[i] - med), 2);
        i++;
    }
    return soma / n;
}
float maior(float v[], int n){
    float m = v[0];
    int i = 1;
    while(i < n){
        if(m < v[i]){
            m = v[i];
        }
        i++;
    }
    return m;
}

float menor(float v[], int n){
    float m = v[0];
    int i = 1;
    while(i < n){
        if(m > v[i]){
            m = v[i];
        }
        i++;
    }
    return m;
}

int produtoescalar(int v[], int u[], int n){
    int i = 0;
    int soma = 0;
    while(i < n){
        soma = soma + (v[i] * u[i]);
        i++;
    }
    return soma;
}

int main() {
    int numeros[1000];
    int quantidade = 0;

    FILE *arquivo = fopen("numeros.txt", "r");

    while (fscanf(arquivo, "%d", &numeros[quantidade]) == 1) {
        quantidade++;
    }

    fclose(arquivo);

    int i = 0;
    printf("1) ");
    while (i < quantidade) {
        printf("%d ", numeros[i]);
        i++;
    }

    float v[] = {1, 2, 3, 4, 5};
    int n = 5;


    //produto escalar
    int numerosv[] = {2, 4, 6};
    int numerosu[] = {3, 5, 7};
    int dimensaon = 3;



    printf("\n2) %.f\n", media(v, n));
    printf("3) %.f\n", variancia(v, n));
    printf("4) %.f\n", maior(v, n));
    printf("5) %.f\n", menor(v, n));
    printf("6) %d\n", produtoescalar(numerosv, numerosu, dimensaon));


    
}