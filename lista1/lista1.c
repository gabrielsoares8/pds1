#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(){

    //variáveis questão 2
    double a = 1;
    double b = 2;
    double c = 3;
    double d = 4;
    //variáveis questão 3
    double catetosquadrado = pow(b, 2) +pow(c, 2);

    printf("Gabriel Gomes Soares - Matricula: 2026045954\n");
    


    printf("------Questao 1--------\n");
    printf("a) %d \n", 3+4);
    printf("b) %.2f \n", 7.0 / 4.0);
    printf("c) %.1f\n", pow(3, 2));
    printf("d) %.2f\n", 5.3 * 2.1);
    printf("e) %d\n", 2 * 5 - 2);
    printf("f) %d\n", 2 + 2 * 5);
    printf("g) %d\n", (2 + 5) * 3);
    printf("h) %f\n", sin(3.141502));
    printf("i) %f\n", sqrt(5));
    printf("j) %d\n", 1 + 2 + 3);
    printf("k) %d\n", 1 * 2 * 3);
    printf("l) %.2f\n", (1 + 2 + 3) / 3.0);
    printf("m) %d\n", (2 + 4) * (3 - 1));
    printf("n) %d\n", (9 / 3) + (3 * 2));
    printf("o) %f\n", sin(4.5) + cos(3.7));
    printf("p) %f\n", log(2.3) - log(3.1));
    printf("q) %f\n", log (7) + (log(7) * log(7) - cos(log(7))));
    printf("r) %f\n", (10.3 + 8.4)/50.3 - (10.3 + 8.4));
    printf("s) %f\n", (cos(0.8) + sin(0.8)) * (cos(0.8) - sin(0.8)));

    printf("------Questao 2--------\n");
    printf("a) %.f\n", a + b);
    printf("b) %f \n", a / c);
    printf("c) %.f\n", pow(a, 2));
    printf("d) %.f\n", b * c);
    printf("e) %.f\n", a * b - c);
    printf("f) %.f\n", a + b * c);
    printf("g) %.f\n", (a + b) * c);
    printf("h) %f\n", sin(a));
    printf("i) %f\n", sqrt(b));
    printf("j) %.f\n", a + b + c);
    printf("k) %.f\n", a * b * c);
    printf("l) %.1f\n", (a + b + c) / d);
    printf("m) %.f\n", (a + b) * (a - d));
    printf("n) %f\n", (b / c) + (a * d));
    printf("o) %f\n", sin(b) + cos(c));
    printf("p) %f\n", log(a) - log(c));
    printf("q) %f\n", log (a) + (log(b) * log(d) - cos(log(c))));
    printf("r) %.f\n", (b + a)/c - (d + a));
    printf("s) %f\n", (cos(d) + sin(c)) * (cos(b) - sin(a)));

    printf("------Questao 3--------\n");
    printf("a) %.f\n", (a + b + c)/3); //média
    printf("b) %.2f\n", ((3 * a + 4 * b + 5 * c)/12)); //média ponderada
    printf("c) %f\n", 2 * M_PI * a); //perimetro circulo 
    printf("d) %f\n",M_PI * pow(a, 2) );//área circulo
    printf("e) %.f\n", b * c /2); // área triângulo
    printf("f) %f\n", sqrt(catetosquadrado));

    //variáveis 3-g
    double delta = pow(b, 2) - (4 * a * c);
    double x1, x2;
    if(delta < 0){
        printf("g) Sem raizes reais.\n");
    } else if(delta == 0){
        x1 = -b / (2*a);
        printf("g) Raiz dupla: x = %.2f\n", x1);
    } else {
        x1 = (-b + sqrt(delta)) / (2*a);
        x2 = (-b - sqrt(delta)) / (2*a);
        printf("g) x1 = %.2f\n", x1);
        printf("   x2 = %.2f\n", x2);
    }

}   