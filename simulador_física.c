#include <stdio.h>
#include <math.h>

int main() {

    int opcao;

    // Variáveis utilizadas nos cálculos
    float altura, velocidade, tempo, massa;
    float km_h, km_s;
    float angulo, angulo_rad;
    float altura_max, alcance;
    float energia_potencial, energia_cinetica;

    // Aceleração da gravidade
    const float gravidade = 9.81;

    // Valor de PI
    const float PI = 3.14159265;

    printf("========================================\n");
    printf("       SIMULADOR DE LANCAMENTO\n");
    printf("========================================\n");

    // Menu principal
    do {

        printf("\n");
        printf("--------------- MENU -------------------\n");
        printf("1 - Lancamento obliquo\n");
        printf("2 - Queda livre\n");
        printf("3 - Energia cinetica\n");
        printf("4 - Energia potencial\n");
        printf("5 - Conversao de unidades\n");
        printf("6 - Sair\n");
        printf("-----------------------------------------\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            // Lancamento obliquo
            case 1:

                printf("\n=== LANCAMENTO OBLIQUO ===\n");

                printf("Digite a velocidade inicial (m/s): ");
                scanf("%f", &velocidade);

                printf("Digite o angulo (graus): ");
                scanf("%f", &angulo);

                // Conversao de graus para radianos
                angulo_rad = angulo * PI / 180;

                // Calculos
                tempo = (2 * velocidade * sin(angulo_rad))
                        / gravidade;

                altura_max = (velocidade * velocidade)
                             * sin(angulo_rad)
                             * sin(angulo_rad)
                             / (2 * gravidade);

                alcance = (velocidade * velocidade)
                          * sin(2 * angulo_rad)
                          / gravidade;

                // Resultados
                printf("\n---------- RESULTADOS ----------\n");
                printf("Tempo de voo: %.2f s\n", tempo);
                printf("Velocidade inicial: %.2f m/s\n", velocidade);
                printf("Altura maxima: %.2f m\n", altura_max);
                printf("Alcance: %.2f m\n", alcance);
                printf("--------------------------------\n");

                break;


            // Queda livre
            case 2:

                printf("\n=== QUEDA LIVRE ===\n");

                printf("Digite a altura (m): ");
                scanf("%f", &altura);

                // Calculo do tempo de queda
                tempo = sqrt((2 * altura) / gravidade);

                // Calculo da velocidade final
                velocidade = gravidade * tempo;

                printf("\n---------- RESULTADOS ----------\n");
                printf("Tempo de queda: %.2f s\n", tempo);
                printf("Velocidade final: %.2f m/s\n", velocidade);
                printf("--------------------------------\n");

                break;


            // Energia cinetica
            case 3:

                printf("\n=== ENERGIA CINETICA ===\n");

                printf("Digite a massa (kg): ");
                scanf("%f", &massa);

                printf("Digite a velocidade (m/s): ");
                scanf("%f", &velocidade);

                // Ec = (m * v²) / 2
                energia_cinetica =
                    massa * (velocidade * velocidade) / 2;

                printf("\n---------- RESULTADO ----------\n");
                printf("Energia cinetica: %.2f J\n",
                       energia_cinetica);
                printf("--------------------------------\n");

                break;


            // Energia potencial
            case 4:

                printf("\n=== ENERGIA POTENCIAL ===\n");

                printf("Digite a massa (kg): ");
                scanf("%f", &massa);

                printf("Digite a altura (m): ");
                scanf("%f", &altura);

                // Ep = m * g * h
                energia_potencial =
                    massa * gravidade * altura;

                printf("\n---------- RESULTADO ----------\n");
                printf("Energia potencial: %.2f J\n",
                       energia_potencial);
                printf("--------------------------------\n");

                break;


            // Conversao de unidades
            case 5:

                printf("\n=== CONVERSAO DE UNIDADES ===\n");

                printf("Digite a velocidade em km/h: ");
                scanf("%f", &km_h);

                // km/h para m/s
                km_s = km_h / 3.6;

                printf("\n---------- RESULTADO ----------\n");
                printf("%.2f km/h = %.2f m/s\n",
                       km_h, km_s);
                printf("--------------------------------\n");

                break;


            // Sair
            case 6:

                printf("\n========================================\n");
                printf("       Obrigado por utilizar!\n");
                printf("========================================\n");

                break;


            // Opcao invalida
            default:

                printf("\n[ERRO] Opcao invalida!\n");
                printf("Escolha uma opcao entre 1 e 6.\n");

                break;
        }

    } while (opcao != 6);

    return 0;
}