#include <stdio.h>

// questao 1 (função máximo e mínimo) --------------------------------------------------------
double max(double a, double b, double c){
    double maior;
    maior = a; 
    if(b > a){
        maior = b;
    }
    if (c > b){
        maior = c;
    }
    return maior;  
}

double min(double a, double b, double c){
    double menor;
    menor = a; 
    if( a > b){
        menor = b;
    }
    if (b > c){
        menor = c;
    }
    return menor;  
}
// questao 2 (função par, intervalo e fora intervalo) --------------------------------------------------------
char* par(int x){
    char* par = "O numero e par";
    char* impar = "O numero e impar";

    if(x % 2 == 0){
        return par;
    }
    else{
        return impar;
    }
}

char* dentro(double x, double y, double z){
    char* in = "O numero ta dentro";
    char* out = "O numero nao ta dentro";
    if(x >= y && x<=z){
        return in;
    }
    else{
        return out;
    }
}

char* fora(double x, double y, double z){
    char* in = "O numero nao ta fora";
    char* out = "O numero ta fora";
    if(x >= y && x<=z){
        return in;
    }
    else{
        return out;
    }
}
//questao 3(função bissexto)------------------------------------------------------------

char* bissexto(int ano){
    char* sim = "o ano e bissexto";
    char* nao = "o ano nao e bissexto";

    if(ano % 400 == 0){
        return sim;
    }
    else if(ano % 4 == 0 && ano % 100 != 0){
        return sim;
    }
    else{
        return nao;
    }
}
  
int main(){
    //teste da função max
    printf("O Maior numero e %.1lf\n", max(1, 2 , 3));
    //teste da função min
    printf("O menor numero e %.1lf\n", min(1, 2 , 3));

    //teste da função par
    printf("%s\n", par(9) );
    //teste da função dentro
    printf("%s\n", dentro(3.1, 2, 3) );
    //teste da função fora
    printf("%s\n", fora(3.1, 2, 3) );
    //teste da função bissexto
    printf("%s\n", bissexto(2017) );

}