#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    int ataque;
    int defesa;
    int vida;
    char tipo[20];
} pokemon;

float calcular_multiplicador(char tipo_atacante[], char tipo_defensor[]) {
    if ((strcmp(tipo_atacante, "eletrico") == 0 && strcmp(tipo_defensor, "agua") == 0) ||
        (strcmp(tipo_atacante, "agua") == 0 && strcmp(tipo_defensor, "fogo") == 0) ||
        (strcmp(tipo_atacante, "fogo") == 0 && strcmp(tipo_defensor, "gelo") == 0) ||
        (strcmp(tipo_atacante, "gelo") == 0 && strcmp(tipo_defensor, "pedra") == 0) ||
        (strcmp(tipo_atacante, "pedra") == 0 && strcmp(tipo_defensor, "eletrico") == 0)) {
        return 1.2;
    }

    if ((strcmp(tipo_atacante, "agua") == 0 && strcmp(tipo_defensor, "eletrico") == 0) ||
        (strcmp(tipo_atacante, "fogo") == 0 && strcmp(tipo_defensor, "agua") == 0) ||
        (strcmp(tipo_atacante, "gelo") == 0 && strcmp(tipo_defensor, "fogo") == 0) ||
        (strcmp(tipo_atacante, "pedra") == 0 && strcmp(tipo_defensor, "gelo") == 0) ||
        (strcmp(tipo_atacante, "eletrico") == 0 && strcmp(tipo_defensor, "pedra") == 0)) {
        return 0.8;
    }

    return 1.0;
}

int main() {
    int n, m;

    pokemon jogador1[100];
    pokemon jogador2[100];

    char derrotados[200][50];
    int qtd_derrotados = 0;

    FILE *arquivo = fopen("poke.txt", "r");

    fscanf(arquivo, "%d %d", &n, &m);

    int i = 0;
    while (i < n) {
        fscanf(arquivo, "%s %d %d %d %s",
               jogador1[i].nome,
               &jogador1[i].ataque,
               &jogador1[i].defesa,
               &jogador1[i].vida,
               jogador1[i].tipo);
        i++;
    }

    int j = 0;
    while (j < m) {
        fscanf(arquivo, "%s %d %d %d %s",
               jogador2[j].nome,
               &jogador2[j].ataque,
               &jogador2[j].defesa,
               &jogador2[j].vida,
               jogador2[j].tipo);
        j++;
    }

    int pokemon_atual_1 = 0;
    int pokemon_atual_2 = 0;
    int turno = 1;

    while (pokemon_atual_1 < n && pokemon_atual_2 < m) {

        while (jogador1[pokemon_atual_1].vida > 0 &&
               jogador2[pokemon_atual_2].vida > 0) {

            if (turno == 1) {

                float mult = calcular_multiplicador(
                    jogador1[pokemon_atual_1].tipo,
                    jogador2[pokemon_atual_2].tipo
                );

                int ataque = (int)(jogador1[pokemon_atual_1].ataque * mult);

                int dano;

                if (ataque > jogador2[pokemon_atual_2].defesa)
                    dano = ataque - jogador2[pokemon_atual_2].defesa;
                else
                    dano = 1;

                jogador2[pokemon_atual_2].vida =
                    jogador2[pokemon_atual_2].vida - dano;

                if (jogador2[pokemon_atual_2].vida <= 0)
                    break;

                turno = 2;
            }

            else {

                float mult = calcular_multiplicador(
                    jogador2[pokemon_atual_2].tipo,
                    jogador1[pokemon_atual_1].tipo
                );

                int ataque = (int)(jogador2[pokemon_atual_2].ataque * mult);

                int dano;

                if (ataque > jogador1[pokemon_atual_1].defesa)
                    dano = ataque - jogador1[pokemon_atual_1].defesa;
                else
                    dano = 1;

                jogador1[pokemon_atual_1].vida =
                    jogador1[pokemon_atual_1].vida - dano;

                if (jogador1[pokemon_atual_1].vida <= 0)
                    break;

                turno = 1;
            }
        }

        if (jogador1[pokemon_atual_1].vida <= 0) {

            printf("%s venceu %s\n",
                   jogador2[pokemon_atual_2].nome,
                   jogador1[pokemon_atual_1].nome);

            strcpy(derrotados[qtd_derrotados],
                   jogador1[pokemon_atual_1].nome);

            qtd_derrotados++;
            pokemon_atual_1++;

            if (pokemon_atual_1 < n)
                turno = 1;
        }

        else {

            printf("%s venceu %s\n",
                   jogador1[pokemon_atual_1].nome,
                   jogador2[pokemon_atual_2].nome);

            strcpy(derrotados[qtd_derrotados],
                   jogador2[pokemon_atual_2].nome);

            qtd_derrotados++;
            pokemon_atual_2++;

            if (pokemon_atual_2 < m)
                turno = 2;
        }
    }

    if (pokemon_atual_1 >= n)
        printf("Jogador 2 venceu\n");
    else
        printf("Jogador 1 venceu\n");

    printf("Pokemon sobreviventes:\n");

    int s1 = pokemon_atual_1;
    while (s1 < n) {
        printf("%s\n", jogador1[s1].nome);
        s1++;
    }

    int s2 = pokemon_atual_2;
    while (s2 < m) {
        printf("%s\n", jogador2[s2].nome);
        s2++;
    }


    printf("Pokemon derrotados:\n");

    int d = 0;
    while (d < qtd_derrotados) {
        printf("%s\n", derrotados[d]);
        d++;
    }

    printf("\n");

    fclose(arquivo);
    return 0;
}