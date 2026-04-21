#include <stdio.h> 

int fat(int n){ //letra a
        int fatorial = 1;
        while(n > 0){
            fatorial = fatorial * n;
            n--;
        }
        return fatorial; 
    }

int mdc(int a, int b){ //letra b
    int i = 1;
    int resultado = 1;
    while(i <= a && i <= b){
        if(a % i == 0 && b % i == 0){
            resultado = i;
        }
        i++;
    }
    return resultado;
}

int mdc3(int a, int b, int c){ //letra c
    int i = 1;
    int resultado = 1;
    while(i <= a && i <= b && i<= c){
        if(a % i == 0 && b % i == 0 && c % i == 0){
            resultado = i;
        }
        i++;
    }
    return resultado; 
}

int fib(int n){ //letra d
    int anterior = 1;
    int atual = 1;
    int i = 2;

    while(i < n){
        int proximo = anterior + atual;
        anterior = atual;
        atual = proximo;
        i++;
    }

    return atual;
}

char* primo(int x){ //letra e
    int i = 2;
    while(i < x){
        if(x % i == 0){
            return "Nao e primo";
        }
        i++;
    }
    return "Primo";
}

void decrescente(int x){ //letra f
    int i = x - 1;
    while(i > 0){
        printf("%d ", i);
        i--;
    }
    printf("\n");
}

int res(int a, int b){ //letra g
    int resto = a % b;
    return resto;
}

int form(int n){ //letra h
    int i = 1;
    int soma = 0;
    while(i <= n){
        soma = soma + (i * i);
        i++;
    }
    return soma;
}

int mmc(int a, int b){ //letra i
    int i = a;
    while(i % a != 0 || i % b != 0){
        i++;
    }
    return i;
}

int divint(int a, int b){ //letra j
    return a / b;
}

float sqrtn(int n){ //letra l
    float i = 0;
    while(i * i < n){
        i = i + 0.001;
    }
    return i;
}

int dig(int n){ //letra m
    int soma = 0;
    while(n > 0){
        soma = soma + (n % 10);
        n = n / 10;
    }
    return soma;
}

int expp(int k, int n){ //letra n
    int resultado = 1;
    int i = 0;
    while(i < n){
        resultado = resultado * k;
        i++;
    }
    return resultado;
}

void crescente(int x){ //letra o
    int i = 1;
    while(i <= x){
        printf("%d ", i);
        i++;
    }
    printf("\n");
}

int main(){
    printf("Nome: Gabriel Gomes Soares\n");
    printf("Matricula: 2026045954\n\n");

    //letra a 
    printf("O valor de 5 fatorial e: %d\n", fat(5));

    //letra b
    printf("o mdc de 50 e 25 e: %d\n", mdc(50, 25));
    
    //letra c
    printf("o mdc de 12, 8 e 4 e: %d\n", mdc3(12, 8, 4));

    //letra d
    printf("o oitavo numero da sequencia de fibonacci e: %d\n", fib(8));

    //letra e
    printf("testando se 13 e primo ou nao: %s\n", primo(13));

    //letra f
    printf("sequencia decrescente menor que 5 e maior que 0: ");
    decrescente(5);

    //letra g
    printf("o resto da divisao de 10 por 3 e: %d\n", res(10, 3));

    //letra h
    printf("o somatorio de i*i com i de 1 ate 4 e: %d\n", form(4));

    //letra i
    printf("o mmc de 4 e 6 e: %d\n", mmc(4, 6));

    //letra j
    printf("a divisao inteira de 10 por 3 e: %d\n", divint(10, 3));

    //letra l
    printf("a raiz quadrada de 25 e: %.3f\n", sqrtn(25));

    //letra m
    printf("a soma dos digitos de 132 e: %d\n", dig(132));

    //letra n
    printf("2 elevado a 10 e: %d\n", expp(2, 10));

    //letra o
    printf("sequencia crescente de 1 ate 5: ");
    crescente(5);

    return 0;
}