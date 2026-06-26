#include <stdio.h>

int fat(int n){
    if(n == 0) return 1;
    if (n == 1) return 1;
    
    return n * fat(n - 1);
}

int mdc(int a, int b) {
    if (b == 0) {
        return a;
    }
    
    return mdc(b, a % b);
}

int mdc3(int a, int b, int c){
    int primeiromdc = mdc(a, b);
    return mdc(primeiromdc, c); 
}

int fib(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;

    return fib(n-1) + fib(n-2);
}

int primo_aux(int x, int i) {
    if (i == 1) return 1;
    if (x % i == 0) return 0;
    return primo_aux(x, i - 1);
}

int primo(int x) {
    if (x <= 1) return 0;
    return primo_aux(x, x - 1);
}

void decrescente(int x) {
    if (x <= 1) return;
    printf("%d ", x - 1);
    decrescente(x - 1);
}

int res(int a, int b) {
    if (a < b) return a;
    return res(a - b, b);
}

int form(int n) {
    if (n == 1) return 1;
    return (n * n) + form(n - 1);
}

int mmc(int a, int b) {
    return (a * b) / mdc(a, b);
}

int div(int a, int b) {
    if (a < b) return 0;
    return 1 + div(a - b, b);
}

double sqrt_aux(double n, double chute) {
    double proximo = (chute + n / chute) / 2.0;
    double diferenca = proximo - chute;
    if (diferenca < 0) diferenca = -diferenca;
    if (diferenca < 0.001) return proximo;
    return sqrt_aux(n, proximo);
}

double sqrt_rec(double n) {
    if (n == 0) return 0;
    return sqrt_aux(n, n / 2.0);
}

int dig(int n) {
    if (n == 0) return 0;
    return (n % 10) + dig(n / 10);
}

int exp_rec(int k, int n) {
    if (n == 0) return 1;
    return k * exp_rec(k, n - 1);
}

void crescente(int x) {
    if (x <= 0) return;
    crescente(x - 1);
    printf("%d ", x);
}

int main(){
   printf("Lista 4 recursao\n");
   printf("Gabriel Gomes Soares\n\n");

   printf("a) %d\n", fat(4));
   printf("b) %d\n", mdc(4, 8));
   printf("c) %d\n", mdc3(5, 10, 15));
   printf("d) %d\n", fib(4));
   printf("e) %d\n", primo(7));
   printf("f) "); decrescente(5); printf("\n");
   printf("g) %d\n", res(7, 3));
   printf("h) %d\n", form(3));
   printf("i) %d\n", mmc(4, 6));
   printf("j) %d\n", div(7, 3));
   printf("l) %.3f\n", sqrt_rec(9));
   printf("m) %d\n", dig(132));
   printf("n) %d\n", exp_rec(2, 3));
   printf("o) "); crescente(5); printf("\n");

   return 0;
}