#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

double media(double a, double b, double c) {
    return (a + b + c) / 3.0;
}

double media_ponderada(double a, double b, double c) {
    return (a * 3 + b * 4 + c * 5) / (3 + 4 + 5);
}

double perimetro_circulo(double r) {
    return 2 * PI * r;
}

double area_circulo(double r) {
    return PI * r * r;
}

double area_triangulo(double b, double c) {
    return (b * c) / 2.0;
}

double area_caixa(double a, double b, double c) {
    return 2 * (a*b + b*c + a*c);
}

double volume_caixa(double a, double b, double c) {
    return a * b * c;
}

double area_cilindro(double r, double h) {
    return 2 * PI * r * (r + h);
}

double volume_cilindro(double r, double h) {
    return PI * r * r * h;
}

double hipotenusa(double b, double c) {
    return sqrt(b*b + c*c);
}

double raiz_positiva(double a, double b, double c) {
    double delta = b*b - 4*a*c;
    if (delta < 0) {
        printf("  [AVISO] Delta negativo, sem raiz real!\n");
        return -1;
    }
    double r1 = (-b + sqrt(delta)) / (2*a);
    double r2 = (-b - sqrt(delta)) / (2*a);
    return (r1 >= 0) ? r1 : r2;
}

// ─── EXERCÍCIO 2: testes de verificação ───────────────────────────────────────
int main() {
    printf("=== EXERCICIO 1 + 2: Funcoes e Verificacao ===\n\n");

    printf("Nome: Gabriel Gomes Soares\n");
    printf("Matricula: 2026045954\n\n");


    // a)
    printf("a) Media(3, 5, 7)          = %.2f  (esperado: 5.00)\n",
           media(3, 5, 7));

    // b)
    printf("b) Media pond.(3, 5, 7)    = %.2f  (esperado: 5.25)\n",
           media_ponderada(3, 5, 7));

    // c)
    printf("c) Perimetro circulo r=5   = %.4f  (esperado: 31.4159)\n",
           perimetro_circulo(5));

    // d)
    printf("d) Area circulo r=5        = %.4f  (esperado: 78.5398)\n",
           area_circulo(5));

    // e)
    printf("e) Area triangulo b=4 h=6  = %.2f  (esperado: 12.00)\n",
           area_triangulo(4, 6));

    // f)
    printf("f) Area caixa 2x3x4        = %.2f  (esperado: 52.00)\n",
           area_caixa(2, 3, 4));

    // g)
    printf("g) Volume caixa 2x3x4      = %.2f  (esperado: 24.00)\n",
           volume_caixa(2, 3, 4));

    // h)
    printf("h) Area cilindro r=3 h=7   = %.4f  (esperado: 188.4956)\n",
           area_cilindro(3, 7));

    // i)
    printf("i) Volume cilindro r=3 h=7 = %.4f  (esperado: 197.9203)\n",
           volume_cilindro(3, 7));

    // j)
    printf("j) Hipotenusa b=3 c=4      = %.2f  (esperado: 5.00)\n",
           hipotenusa(3, 4));

    // k) x² - 5x + 6 = 0  →  raízes 3 e 2, positiva maior = 3
    printf("k) Raiz positiva x2-5x+6   = %.2f  (esperado: 3.00)\n",
           raiz_positiva(1, -5, 6));

    return 0;
}

