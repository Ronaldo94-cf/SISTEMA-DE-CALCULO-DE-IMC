#include <stdio.h>

int main() {
    int opcao;
    int contadorUsuarios = 0;  //  Contador de quantos usuários já calcularam
    float somaIMC = 0;         //  Soma dos IMCs para calcular a média
    
    printf("======================================\n");
    printf("    SISTEMA DE CALCULO DE IMC (BMI)\n");
    printf("======================================\n");
    printf("Este programa calcula o IMC de varios usuarios,\n");
    printf("Classifica os resultados e mostra a media geral.\n\n");
    
    do {
        printf("\n============MENU PRINCIPAL===========\n");
        printf("1 - Calcular IMC\n");
        printf("2 - Mostrar media geral dos IMCs\n");
        printf("3 - Sair\n ");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao); // CORRIGIDO
        
        switch (opcao) {
            case 1: {
                float peso, altura, imc;
                
                printf("\nDigite o peso (Kg): ");
                scanf("%f", &peso); // CORRIGIDO
                
                printf("\nDigite a altura (m): ");
                scanf("%f", &altura); // CORRIGIDO
                
                if (peso <= 0 || altura <= 0) {
                    printf("Valores invalidos! Tente novamente.\n");
                    break;
                }
                
                imc = peso / (altura * altura);
                printf("IMC calculado: %.2f\n", imc);
                
                if (imc < 18.5) {
                    printf("Classificacao: Abaixo do peso.\n");
                } else if (imc < 24.9) {
                    printf("Classificacao: Peso normal.\n");
                } else if (imc < 29.9) {
                    printf("Classificacao: Sobrepeso.\n");
                } else if (imc < 34.9) {
                    printf("Classificacao: Obesidade grau I.\n");
                } else if (imc < 39.9) {
                    printf("Classificacao: Obesidade grau II.\n");
                } else {
                    printf("Classificacao: Obesidade grau III.\n");
                }
                
                contadorUsuarios++;            // CORRIGIDO
                somaIMC += imc;                // CORRIGIDO
                break;
            }
            
            case 2:
                if (contadorUsuarios == 0) {
                    printf("\nAinda nao ha usuarios cadastrados.\n");
                } else {
                    float media = somaIMC / contadorUsuarios;
                    printf("\nTotal de usuarios: %d\n", contadorUsuarios);
                    printf("Media geral dos IMCs: %.2f\n", media);
                }
                break;
                
            case 3:
                printf("\nEncerrando o programa...\n");
                printf("Obrigado por utilizar o sistema de IMC!\n");
                break;
                
            default:
                printf("\nOpcao invalida! Escolha novamente.\n");
        }
        
    } while (opcao != 3);
    
    return 0;
}