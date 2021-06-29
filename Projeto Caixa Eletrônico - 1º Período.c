#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
    
    
    float saldo, newPix, transpix = 0;

    float dig_invalido(float invalido){

        if(invalido <= 0)

            return 0;

    }

    float pix(float send_pix){

        int i, somador = 0, digito1, result1, result2, digito2, valor, icpf[12];
        char pixx [12], cpf[12];

        printf("INFORME A CHAVE PIX (CPF): ");  
        scanf("%s", cpf);
        fflush(stdin);  
        
        //Efetua a conversao de array de char para um array de int.  
        for(i=0;i<11;i++)  
        {  
        icpf[i]=cpf[i]-48;  
        }  
        
        //PRIMEIRO DIGITO.  
        
        for(i=0;i<9;i++)  
        {  
        somador+=icpf[i]*(10-i);  
        }  
        
        result1=somador%11;  
        
        if( (result1==0) || (result1==1) )  
        {  
        digito1=0;  
        }  
        
        else  
        {  
        digito1 = 11-result1;  
        }  
        
        //SEGUNDO DIGITO.  
        
        somador=0;  
        
        for(i=0;i<10;i++)  
        {  
        somador+=icpf[i]*(11-i);  
        }  
        
        valor=(somador/11)*11;  
        result2=somador-valor;  
        
        if( (result2==0) || (result2==1)) 
        {  
        digito2=0;  
        }  
        
        else  
        {  
        digito2=11-result2;  
        }  
        
        //RESULTADOS DA VALIDACAO.  
        
        if((digito1==icpf[9]) && (digito2==icpf[10])){

            printf("\nVALOR A TRANSFERIR\nR$: ");
            fflush(stdin);
            scanf("%f", &transpix);

            if(transpix <= saldo && transpix > 0){

                saldo = saldo - transpix;
                newPix = transpix;
                transpix = 0;

        printf("\nPIX ENVIADO COM SUCESSO...\n");
        
        }  else if(transpix < 0){

               dig_invalido(transpix);

               printf("_________________\nDIGITO INV%cLIDO\n_________________\n", 181);
            

        }  else if(transpix > saldo) {

               printf("___________________\nSALDO INSUFICIENTE\n___________________\n");

        } else {

                printf("\nDIGITE UM NUMERO MAIOR QUE 0\n");
                   
        }

        } else {  
            
            printf("\n[CPF INVALIDO]\n");

        }
    }

    int main() {

    //DECLARAÇÃO DE VARIÁVEIS
    int op, op_ext, ign, qtd;
    float sacar = 0, deposito = 0, transf = 0, newTransf, newSacar, newDeposito;
    char exit, linha [1000][50];        

    do {

        //Abre o saldo atual do usuário
        FILE *open_ext = fopen("Saldo.txt", "r");
        fscanf(open_ext, "%f", &saldo);
        fclose(open_ext);

        printf("\t\t\t\t\t\t________________________\n\t\t\t\t\t\tSALDO ATUAL: R$ %.2f\n\t\t\t\t\t\t________________________\n", saldo);

        //MENU DE OPÇÕES
        printf("___________________________\nINFORME A OPERA%c%cO DESEJADA\n___________________________\n", 128, 199);
       //printf("___________________________\n");
        printf("\n[1] TRANSFER%cNCIA\n", 210);
        printf("\n[2] DEP%cSITO\n", 224);
        printf("\n[3] SAQUE\n");
        printf("\n[4] EXTRATO\n");
        printf("\n[5] PIX\n");
        scanf("%d", &op);


            //ABAIXO TEREMOS AS FUNCIONALIDADES DO PROGRAMA//

    switch(op){

    //TRANSFERÊNCIA: Verifica o valor na conta e transfere se houver saldo
    case 1:

        printf("\nDIGITE O VALOR DA TRANSFER%cNCIA:\nR$ ", 210);
        scanf("%f", &transf);

    if(transf <= saldo && transf > 0){

        saldo = saldo - transf;
        newTransf = transf;
        transf = 0;

        printf("______________________________________\nTRANSFER%cNCIA DE R$ %.2f BEM SUCEDIDA\n______________________________________\n", 210, newTransf);

    } else if(transf < 0) {

        dig_invalido(transf);

        printf("_________________\nDIGITO INV%cLIDO\n_________________\n", 181);

    } else if(transf > saldo) {

        printf("____________________\nSALDO INSUFICIENTE\n____________________\n");

    } else {

                printf("\nDIGITE UM N%cMERO MAIOR QUE 0\n", 233);
                   
    }
    
    break;

    //DEPÓSITO: Deposita um valor indicado
    case 2:

        printf("\nVALOR DO DEP%cSITO:\nR$ ", 224);
        scanf("%f", &deposito);

            if(deposito <= 0){

                dig_invalido(deposito);

                printf("_________________\nDIGITO INV%cLIDO\n_________________\n", 181);

                break;

    } else {

                saldo = saldo + deposito;
                newDeposito = deposito;
                deposito = 0;

                printf("______________________________\nDEP%cSITO DE R$ %.2f REALIZADO\n______________________________\n", 224, newDeposito);

    }   break;

    //SAQUE: Efetua o saque se houver saldo disponível
    case 3:

        printf("VALOR DO SAQUE:\nR$ ");
        scanf("%f", &sacar);

            if(sacar <= saldo && sacar > 0){

                saldo = saldo - sacar;
                newSacar = sacar;
                sacar = 0;

                printf("________________________________________\nSAQUE DE R$ %.2f REALIZADO COM SUCESSO\n________________________________________\n", newSacar);

    } else if(sacar < 0) {

            dig_invalido(sacar);

                printf("________________\nDIGITO INV%cLIDO\n________________\n", 181);

    } else if(sacar > saldo) {

                printf("___________________\nSALDO INSUFICIENTE\n___________________\n");

    } else {

                printf("\nDIGITE UM N%cMERO MAIOR QUE 0\n", 233);
                   
    }
    break;

    //EXTRATO: Imprime, exibe e classifica por período as últimas movimentações da conta
    case 4:

        printf("-> [1] IMPRIMIR EXTRATO\n");
        printf("-> [2] EXIBIR NA TELA\n");
        printf("-> [3] %cLTIMOS EXTRATOS\n", 233);
        scanf("%d", &op_ext);

            //Salva a movimentação da conta
            if(op_ext == 1){

            

            struct  {

                int tm_mday;
                int tm_mon;
                int tm_year;
                int tm_hour;
                int tm_min;

            };

            struct tm *data_hora_atual;
            time_t segundos;

                time(&segundos);
                data_hora_atual = localtime(&segundos);

                FILE *save_ext = fopen("Extrato.txt", "a");

                fprintf(save_ext, "MOVIMENTA%c%cO DO DIA: %.2d/%.2d/%.2d as %.2d:%.2d\n\n", 128, 199, data_hora_atual->tm_mday, data_hora_atual->tm_mon+1, data_hora_atual->tm_year+1900, data_hora_atual->tm_hour, data_hora_atual->tm_min);
                fprintf(save_ext, "Transfer%cncia: R$ " "%.2f \n", 136, newTransf);
                fprintf(save_ext, "Dep%csito: R$ " "%.2f \n", 162, newDeposito);
                fprintf(save_ext, "PIX Enviado: R$ " "%.2f \n", newPix);
                fprintf(save_ext, "Saque: R$ " "%.2f \n\n", newSacar);
                fprintf(save_ext, "Saldo: R$ " "%.2f \n\n", saldo);

                //Fecha o arquivo
                fclose(save_ext);

                printf("___________________\nRETIRE SEU EXTRATO\n___________________\n");

                break;
            }

            

            //Exibe na tela as movimentações da conta
            if(op_ext == 2){

                FILE *open_ex = fopen("Extrato.txt", "r");

                //Se houver algum erro no arquivo, ele retorna uma mensagem
                if(open_ex == NULL){

                    printf("\n[ERRO AO EXIBIR EXTRATOS]\n");
                    break;

                }

                while(fgets(linha, 50, open_ex) != NULL){

                    printf("%s", linha);

                }
                fclose(open_ex);

                break;

                }

            if(op_ext == 3){

                int count = 1;

                FILE *open_ex = fopen("Extrato.txt", "r");

                    if(open_ex == NULL){

                        printf("\n[ERRO AO EXIBIR EXTRATOS]\n");
                        break;
                    }

                printf("[DIGITE A QUANTIDADE]: ");
                scanf("%d", &qtd);

                if(qtd < 0){

                    dig_invalido(qtd);

                    printf("________________\nDIGITO INV%cLIDO\n________________\n", 181);
                    break;

                }  else if(qtd == 0) {

                    printf("\nDIGITE UM N%cMERO MAIOR QUE 0\n", 233);
                    break;
                }     

                while(fgets(linha[count], 50, open_ex) != NULL){

                count++;

                }

                ign = (count/9) - qtd;

                if(ign < 0){

                    printf("\n\t[NAO HA ESSA QUANTIDADE DE EXTRATO]\n");
                    break;

                }

                if(qtd == 1){

                    printf("\n\t[SUA %cLTIMA MOVIMENTA%c%cO]\n\n", 233, 128, 199);

                } else {

                    printf("\n\t[SUAS %d ULTIMAS MOVIMENTA%cOES]\n\n", qtd, 128);

                }
            
                for(int i = ign*9; i < count; i++){

                    printf("%s", linha[i]);

                }

                fclose(open_ex);
                break;

            }  else {

                printf("\n[OP%c%cO INV%cLIDA]\n", 128, 199, 181);
                break;
            }

    case 5:

            pix(transpix);
            break;     
        
            //ERROR: Exibe uma mensagem de erro caso não selecione uma opção correta
            default : printf("__________________\nOP%c%cO INEXISTENTE\n__________________\n", 128, 199);

        }

            FILE *save_saldo = fopen("Saldo.txt", "w");
            fprintf(save_saldo, "%.2f", saldo);
            fclose(save_saldo);

                //Pergunta sempre se o usuario deseja fazer mais operações
                printf("\n[DIGITE 'S' PARA CONTINUAR OU QUALQUER TECLAR PARA ENCERRAR]\n");
                scanf("%s", &exit);

                //Limpa a tela a cada execução finalizada
                system("cls");

        //Encerra o programa salvando o saldo atualizado
            } while(exit == 's' || exit == 'S');{

                FILE *save_saldo = fopen("Saldo.txt", "w");
                fprintf(save_saldo, "%.2f", saldo);
                fclose(save_saldo);

                printf("\t\t\t\t\t\t__________________________\n\t\t\t\t\t\tSUA SESSAO FOI ENCERRADA!\n\t\t\t\t\t\t__________________________\n");

                if(newSacar >= 1 || newDeposito >= 1 || newTransf >= 1 || newPix >= 1){

                    struct  {

                    int tm_mday;
                    int tm_mon;
                    int tm_year;
                    int tm_hour;
                    int tm_min;

                };

                    struct tm *data_hora_atual;
                        time_t segundos;

                        time(&segundos);
                        data_hora_atual = localtime(&segundos);

                        FILE *save_ext = fopen("Extrato.txt", "a");

                        fprintf(save_ext, "MOVIMENTA%c%cO DO DIA: %.2d/%.2d/%.2d as %.2d:%.2d\n\n", 128, 199, data_hora_atual->tm_mday, data_hora_atual->tm_mon+1, data_hora_atual->tm_year+1900, data_hora_atual->tm_hour, data_hora_atual->tm_min);
                        fprintf(save_ext, "Transfer%cncia: R$ " "%.2f \n", 136, newTransf);
                        fprintf(save_ext, "Dep%csito: R$ " "%.2f \n", 162, newDeposito);
                        fprintf(save_ext, "PIX Enviado: R$ " "%.2f \n", newPix);
                        fprintf(save_ext, "Saque: R$ " "%.2f \n\n", newSacar);
                        fprintf(save_ext, "Saldo: R$ " "%.2f \n\n", saldo);

                        //Fecha o arquivo
                        fclose(save_ext);
                
                }

            }

    return 0;
}
