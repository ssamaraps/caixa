/******************************************************************/
/* Aluno1: Samara Porto Souza - Número de matrícula: 8124885      */
/* Número de matrícula: 8124885                                   */
/* Exercício-Programa 1 — Caixa Eletrônico                        */
/* Programação Avançada - 2024 - Professor: Bruno Perillo         */
/* Compilador: gcc versão 10.2.0 (GDB online) */
/******************************************************************/

#include <stdio.h>

int main() {
    int cedulas[7], operacao, valor, saque_possivel, total_cedulas;
    int valores_cedulas[7] = {100, 50, 20, 10, 5, 2, 1};
    
    for (int i = 0; i < 7; i++) {
        scanf("%d", &cedulas[i]);
    }

    while (1) {
        scanf("%d", &operacao);
        if (operacao == -1) break;

        if (operacao == 0) {
            scanf("%d", &valor);
            int temp_cedulas[7], temp_valor = valor;
            saque_possivel = 1;
            
            for (int i = 0; i < 7; i++) {
                temp_cedulas[i] = valor / valores_cedulas[i];
                if (temp_cedulas[i] > cedulas[i]) temp_cedulas[i] = cedulas[i];
                valor -= temp_cedulas[i] * valores_cedulas[i];
            }

            if (valor > 0) {
                saque_possivel = 0;
                printf("Saque de R$ %d não realizado por falta de cédulas\n", temp_valor);
            } else {
                for (int i = 0; i < 7; i++) {
                    cedulas[i] -= temp_cedulas[i];
                }
                printf("Saque de R$ %d efetuado\n", temp_valor);
            }
        } else if (operacao == 1) {
            for (int i = 0; i < 7; i++) {
                int deposito;
                scanf("%d", &deposito);
                cedulas[i] += deposito;
            }
            printf("Depósito efetuado\n");
        }

        total_cedulas = 0;
        for (int i = 0; i < 7; i++) {
            printf("%d ", cedulas[i]);
            total_cedulas += cedulas[i] * valores_cedulas[i];
        }
        printf("Total: %d\n", total_cedulas);
    }

    return 0;
}

