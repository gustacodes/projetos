#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

float negativo(float neg)
{

    if (neg < 0)
    {

        printf("DIGITO INVALIDO\n");
    }
}

int main()
{
    float uber = 0, despesas = 0, despesa = 0, lucro, lucroTotal = 0, meta = 0, calc = 0;
    int v, op, count = 1, opc, parc, qt, exit;
    char consult[1000][50];

    do{

        FILE *fp = fopen("Saldo.txt", "r");

        fscanf(fp, "%f", &lucroTotal);

        fclose(fp);

        fp = fopen("Meta.txt", "r");

        fscanf(fp, "%f", &meta);

        fclose(fp);

        printf("\t\t\t\t\t*************************************");
        printf("\n\t\t\t\t\tLUCRO ATE O MOMENTO: R$ %.2f/%2.f\n", lucroTotal, meta);

        if (lucroTotal >= meta)
        {

            printf("\t\t\t\t\t\t[META MENSAL ATINGIDA]\n\n");
        }

        printf("\t\t\t\t\t-------------------------------------\n");

        fp = fopen("despesas.txt", "r");

        fscanf(fp, "%f", &calc);

        printf("\t\t\t\t\tDESPESAS ATE O MOMENTO: R$ %.2f\n", calc);
        printf("\t\t\t\t\t*************************************\n");

        fclose(fp);

        printf("\n\t\t\t\t\t       [ESCOLHA UMA DAS OPCOES]\n\n\t\t\t\t       [1] ADICIONAR | [2] CONSULTAR | [3] META\n");
        printf("\t\t\t\t\t\t         ");scanf("%d", &op);

        switch (op)
        {

        case 1:

            printf("GANHOS DE HOJE COM A UBER\nR$ ");
            scanf("%f", &uber);

            if (uber < 0){

                negativo(uber);
                break;
            }

            printf("COMBUSTIVEL E OUTROS:\nR$ ");
            scanf("%f", &despesa);

            if (despesa < 0){

                negativo(despesa);
                break;
            }

            fp = fopen("despesas.txt", "r");

            fscanf(fp, "%f", &despesas);

            calc = despesas + despesa;

            fp = fopen("despesas.txt", "w");

            if(fp == NULL){

                printf("ERRO AO ABRIR ARQUIVO\n");

            }

            fprintf(fp, "%.2f", calc);

            fclose(fp);

            printf("\n[DESPESAS DO DIA: R$ %.2f] | ", despesa);

            if (lucro == 0){

                lucro = uber - despesa;
                printf("NAO HOUVE LUCRO HOJE: R$ %.2f\n", lucro);

            }
            else if (lucro < 0){

                lucro = uber - despesa;
                printf("PREJUIZO DE: R$ %.2f\n", lucro);

            }
            else {

                lucro = uber - despesa;
                printf("[LUCRO DE HOJE: R$ %.2f]\n\n", lucro);

            }

            printf("DIGITE [1] PARA SALVAR\n");
            scanf("%d", &v);

            lucroTotal = lucroTotal + lucro;

            FILE *fp = fopen("Saldo.txt", "w");
            fprintf(fp, "%.2f", lucroTotal);
            fclose(fp);

            if (v == 1)
            {

                fp = fopen("Lucros.txt", "a");

                fprintf(fp, "GANHOS COM A UBER: %.2f\n", uber);
                fprintf(fp, "LUCRO DO DIA: %.2f\n", lucro);
                fprintf(fp, "DESPESAS DO DIA: %.2f\n\n", despesa);
                fprintf(fp, "----------------------------\n");

                printf("GANHOS SALVOS COM SUCESSO!\n\n");
            }
            else
            {

                printf("PROGRAMA ENCERRADO!\n");
            }

            fclose(fp);
            break;

        case 2:

            printf("-> [1] GANHOS TOTAIS\n");
            printf("-> [2] ULTIMOS GANHOS\n");
            scanf("%d", &opc);

            if (opc == 1)
            {

                fp = fopen("Lucros.txt", "r");

                while (fgets(consult, 50, fp) != NULL)
                {

                    printf("%s", consult);
                }

                fclose(fp);
                break;
            }
            if (opc == 2)
            {

                fp = fopen("Lucros.txt", "r");

                while (fgets(consult[count], 50, fp) != NULL){

                    count++;
                }

                printf("INSIRA OS ULTIMOS QUE DESEJA VER: ");
                scanf("%d", &qt);
                printf("\n");

                parc = (count / 5) - qt;

                for (int i = parc * 5; i < count; i++)
                {

                    printf("%s", consult[i]);
                }

                fclose(fp);
                break;
            }

        case 3:

            fp = fopen("Meta.txt", "w");

            printf("DEFINA SUA META MENSAL: ");
            scanf("%f", &meta);

            if (meta <= 0)
            {

                printf("INFORME UM VALOR MAIOR QUE 0\n");
                break;
            }
            else
            {

                fprintf(fp, "%.2f", meta);
                printf("\nMETA DE %.2f DEFINIDA\n", meta);
            }

            fclose(fp);
        }

        printf("\nDIGITE [1] PARA RETORNAR\n");
        scanf("%d", &exit);

        system("cls");

    } while (exit == 1);
    {

        lucroTotal = lucroTotal + lucro;

        FILE *fp = fopen("Saldo.txt", "w");
        fprintf(fp, "%.2f", lucroTotal);
        fclose(fp);

        printf("PROGRAMA ENCERRADO\n");
    }

    return 0;
}