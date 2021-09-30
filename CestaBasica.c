#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

    //Programa de controle para a Alencar Cesta Básica//
    
    typedef struct data DATA;
    struct data
    {
        int dia;
        int mes;
        int ano;
    };

    typedef struct cadastro CADASTRO;
    struct cadastro 
    {

        char nome [100];
        char name [100];
        char tel [15];
        char end [150];
        char ref [100];
        char cidade [20];
        char bairro [20];
        int valor;
        DATA venci;
        
    };

    typedef struct funcionarios FUNCIONARIOS;
    struct funcionarios {

        char nome [100];
        char telefone [15];
        int salario;
         
    };

    void cabecalho();
    void clientes();
    void listar();
    void pesquisar();
    void vencimento();
    void pagamentos();
    void alterarCadastro();
    void financeiro();

    int main(){

        SetConsoleTitle("ALENCAR CESTA BASICA - Versao: 1.0");

    int menu, back, sub;
    float valor;
    char senha [10] = "semundial", password [10];
    FILE* arquivo;

    printf("\t\t\t\t\t\tSENHA DE ACESSO: ");
    gets(password);

    do {

        if(strcmp(password, senha) != 0){

            printf("\n\t\t\t\t\t       SENHA INCORRETA KKKKKKKK\n\n");
            break;
        }

    cabecalho();
    arquivo = fopen("C:\\Users\\gusta\\Desktop\\Projetos\\CestasAlencar\\Financeiro\\valor.txt", "r");
    fscanf(arquivo, "%f", &valor);
    fclose(arquivo);
    printf("\t\t\t\t\t\t   ARMAZEM: R$ %.2f\n\n", valor);
    printf("\t\t\t\t\t\t[ESCOLHA UMA DAS OPCOES]\n\n");
    printf("\t\t\t\t  [1] CLIENTES | [2] COBRANCA | [3] FINANCEIRO | [0] SAIR\n");
    printf("\t\t\t\t\t\t\t  ");scanf("%d", &menu);

    switch(menu) {
    
    case 1:

    cabecalho();

    printf("\t\t\t\t\t\t[ESCOLHA UMA DAS OPCOES]\n\n");
    printf("\t\t\t\t    [1] AGENDA | [2] BUSCAR | [3] CADASTRAR | [4] ALTERAR\n");
    printf("\t\t\t\t\t\t\t    ");scanf("%d", &sub);

        if(sub > 4){

            printf("\n[OPCAO INVALIDA]\n");
            break;
        }

        if(sub == 1){

            listar();
            break;
        }

        if(sub == 2){

            pesquisar();
            break;
        }

        if(sub == 3){

            clientes();
            break;
        }

        if(sub == 4){

            alterarCadastro();
            break;
        }

        case 2:

        
        cabecalho();

            printf("\t\t\t\t\t     [1] VENCIMENTOS | [2] PAGAMENTOS\n");
            printf("\t\t\t\t\t\t\t   ");scanf("%d", &sub);

            if(sub == 1){

                vencimento();
                break;

            }

            if(sub == 2){

                pagamentos();
                break;
            }
        case 3:

            financeiro();
            break;

    default: printf("\n[OPCAO INEXISTENTE]\n\n");
    break;

    }

    printf("\nDIGITE [1] PARA RETORNAR\n");
    scanf("%d", &back);

    system("cls");

    } while(back != 0);{

        getch();
        
    }

}

void cabecalho(){

    system("cls");

    printf("\t\t\t\t\t###########################################\n");
    printf("\t\t\t\t\tPROGRAMA DE CONTROLE - ALENCAR CESTA BASICA\n");
    printf("\t\t\t\t\t###########################################\n\n");
}

void clientes(){

    FILE* arquivo;

    CADASTRO clt;

    arquivo = fopen("Clientes.txt", "ab");

    if(arquivo == NULL){

        printf("Erro ao abrir o arquivo\n");

    } else {

        do {

            cabecalho();
            fflush(stdin);

            printf("NOME DO CLIENTE: ");
            gets(clt.nome);

            fflush(stdin);
            printf("CONTATO: ");
            gets(clt.tel);

            fflush(stdin);
            printf("ENDERECO: ");
            gets(clt.end);

            fflush(stdin);
            printf("PONTO DE REF: ");
            gets(clt.ref);

            fflush(stdin);
            printf("CIDADE: ");
            gets(clt.cidade);

            fflush(stdin);
            printf("BAIRRO: ");
            gets(clt.bairro);

            fflush(stdin);
            printf("VALOR: ");
            scanf("%d", &clt.valor);

            fflush(stdin);
            printf("VENCIMENTO: ");
            scanf("%d %d %d", &clt.venci.dia, &clt.venci.mes, &clt.venci.ano);

            fwrite(&clt, sizeof(CADASTRO), 1, arquivo);

            printf("\n%s FOI CADASTRADA(O) COM SUCESSO!\n\n", clt.nome);

            printf("DESEJA CADASTRAR OUTRO CLIENTE? [S/N]\n");
    

        } while(getche() == 's');{
            
            fclose(arquivo);

        }

    }

}

void listar(){

    FILE* arquivo;

    CADASTRO clt;

    int count = 0;

    arquivo = fopen("Clientes.txt", "rb");

    cabecalho();

    printf("\t\t\t\t\t\t[CLIENTES CADASTRADOS]\n\n");

    if(arquivo == NULL){

        printf("Erro ao abrir o arquivo\n");
    } else  {
        
        while(fread(&clt, sizeof(CADASTRO), 1, arquivo) == 1){
            
            count++;

            printf("\tCODIGO: [%d]\n\n", count);
            printf("CLIENTE: %s\n", clt.nome);
            printf("CONTATO: %s\n", clt.tel);
            printf("ENDERECO: %s\n", clt.end);
            printf("PONTO DE REF: %s\n", clt.ref);
            printf("BAIRRO: %s\n", clt.bairro);
            printf("CIDADE: %s\n", clt.cidade);
            printf("---------------------------------------------------------\n\n");
        }

        printf("TOTAL DE CLIENTES: [%d]", count);
        
    }

    fclose(arquivo);
    getch();
}

void pesquisar(){

    FILE* arquivo;

    CADASTRO clt;
    char cli [50];
    int count = 0;

    arquivo = fopen("Clientes.txt", "rb");

    cabecalho();

    if(arquivo == NULL){

        printf("Erro ao abrir o arquivo\n");

    } else {

    int opc;

    printf("\t\t\t\t\t          [1] NOME | [2] BAIRRO\n");
    printf("\t\t\t\t\t\t            ");scanf("%d", &opc);

    if(opc == 1){

    cabecalho();

    fflush(stdin);
    printf("\t\t\t\t\tNOME DO CLIENTE: ");
    gets(cli);
        
        while(fread(&clt, sizeof(CADASTRO), 1, arquivo)){

            count++;

            if(strcmp(cli, clt.nome) == 0){

                printf("\tCODIGO: [%d]\n", count);
                printf("\n\nCLIENTE: %s\t", clt.nome);
                printf("CONTATO: %s\n", clt.tel);
                printf("ENDERECO: %s\t", clt.end);
                printf("PONTO DE REF: %s\n", clt.ref);
                printf("BAIRRO: %s\t", clt.bairro);
                printf("CIDADE: %s\n\n", clt.cidade);
                printf("VALOR: R$ %d\n", clt.valor);
                printf("VENCIMENTO: %.2d/%.2d/%d\n", clt.venci.dia, clt.venci.mes, clt.venci.ano);
                printf("---------------------------------------------------------\n\n");

            }
            
        }
        
    }

    if(opc == 2){

    cabecalho();

    char bai [20];

    fflush(stdin);
    printf("\t\t\t\t\tBAIRRO: ");
    gets(bai);
        
        while(fread(&clt, sizeof(CADASTRO), 1, arquivo)){

            if(strcmp(bai, clt.bairro) == 0){

                count++;
            
                printf("\n\nCLIENTE: %s\t", clt.nome);
                printf("CONTATO: %s\n", clt.tel);
                printf("ENDERECO: %s\t", clt.end);
                printf("PONTO DE REF: %s\n", clt.ref);
                printf("BAIRRO: %s\t", clt.bairro);
                printf("CIDADE: %s\n\n", clt.cidade);
                printf("VALOR: R$ %d\n", clt.valor);
                printf("VENCIMENTO: %.2d/%.2d/%d\n", clt.venci.dia, clt.venci.mes, clt.venci.ano);
                printf("---------------------------------------------------------\n\n");

            }
            
        }

         if(count == 1){

                    printf("[%d] CLIENTE ENCONTRADO\n", count);

                } else {

                    printf("\nFORAM ENCONTRADOS %d CLIENTES\n", count);

                }
    }

    fclose(arquivo);
    getch();

    }

}

void vencimento(){

    FILE* arquivo;
    CADASTRO clt;
    int dia, mes, ano, i = 0;

    cabecalho();

    arquivo = fopen("Clientes.txt", "rb");

        if(arquivo == NULL){

            printf("Erro ao abrir o arquivo\n");

        } else {

            printf("\t\t\t\t\t\tVENCIMENTO: ");
            scanf("\t\t\t\t\t\t%d %d %d", &dia, &mes, &ano);

            while(fread(&clt, sizeof(CADASTRO), 1, arquivo) == 1){

                i++;

                if(i == 1){

                if(dia == clt.venci.dia && mes == clt.venci.mes && ano == clt.venci.ano){


                    printf("\n\t\tCODIGO: [%d]", i);
                    printf("\n\nCLIENTE: %s\t", clt.nome);
                    printf("CONTATO: %s\n", clt.tel);
                    printf("ENDERECO: %s\t", clt.end);
                    printf("PONTO DE REF: %s\n", clt.ref);
                    printf("BAIRRO: %s\t", clt.bairro);
                    printf("CIDADE: %s\n\n", clt.cidade);
                    printf("VALOR: R$ %d\n", clt.valor);
                    printf("VENCIMENTO: %.2d/%.2d/%d\n", clt.venci.dia, clt.venci.mes, clt.venci.ano);
                    printf("---------------------------------------------------------\n");
                                        
                }

                }
                 else if(i >= 2) {

                    if(dia == clt.venci.dia && mes == clt.venci.mes && ano == clt.venci.ano){


                    printf("\n\t\tCODIGO: [%d]", i);
                    printf("\n\nCLIENTE: %s\t", clt.nome);
                    printf("CONTATO: %s\n", clt.tel);
                    printf("ENDERECO: %s\t", clt.end);
                    printf("PONTO DE REF: %s\n", clt.ref);
                    printf("BAIRRO: %s\t", clt.bairro);
                    printf("CIDADE: %s\n\n", clt.cidade);
                    printf("VALOR: R$ %d\n", clt.valor);
                    printf("VENCIMENTO: %.2d/%.2d/%d\n", clt.venci.dia, clt.venci.mes, clt.venci.ano);
                    printf("---------------------------------------------------------\n");

                }
                }
                   
            }

        fclose(arquivo);
        getch();
                
        }
}

void pagamentos(){

    FILE* arquivo;

    CADASTRO clt;

    arquivo = fopen("Clientes.txt", "rb+");

    cabecalho();

    if(arquivo == NULL){

        printf("Erro ao abrir o arquivo\n");

    } else {

    int pag, aux, i = 1, id;

    printf("CODIGO DO CLIENTE: ");
    scanf("%d", &id);
    getchar();
    id--;
        
        while(fread(&clt, sizeof(CADASTRO), 1, arquivo)){

                i++;

            if(id  >= 0 && id < i - 1){

            printf("\n\nCLIENTE: %s\t", clt.nome);
            printf("CONTATO: %s\n", clt.tel);
            printf("ENDERECO: %s\t", clt.end);
            printf("PONTO DE REF: %s\n", clt.ref);
            printf("BAIRRO: %s\t", clt.bairro);
            printf("CIDADE: %s\n\n", clt.cidade);
            printf("VALOR: R$ %d\n", clt.valor);
            printf("VENCIMENTO: %.2d/%.2d/%d\n", clt.venci.dia, clt.venci.mes, clt.venci.ano);
            printf("---------------------------------------------------------\n\n");

            aux  = clt.valor;

            printf("VALOR PAGO: ");
            scanf("%d", &pag);

            if(pag > clt.valor){

                printf("\n[VALOR DE PAGAMENTO MAIOR QUE O DEBITO]\n");
                break;

            } else if(pag <= 0){

                printf("\n[INSIRA UM VALOR MAIOR QUE 0]\n");
                break;

            } else if(pag > 0){

            clt.valor = aux - pag;

            printf("\nRESTA %d DE %s\n\n", clt.valor, clt.nome);
            

            } else {

                printf("\n%s QUITOU", clt.nome);

            }

            printf("PROXIMO VENCIMENTO: ");
            scanf("%d %d %d", &clt.venci.dia, &clt.venci.mes, &clt.venci.ano);

            printf("\nVENCIMENTO AGENDADO PARA: %.2d/%.2d/%d\n", clt.venci.dia, clt.venci.mes, clt.venci.ano);

            fseek(arquivo, id * sizeof(CADASTRO), SEEK_SET);
            fwrite(&clt, sizeof(CADASTRO), 1, arquivo);
            fclose(arquivo);
            break;

            } 

        }

        if(id > i){

            printf("\n[CODIGO INVALIDO]\n");
                
        }

        }   

    }

    void alterarCadastro(){

    FILE* arquivo;

    CADASTRO clt;
    

    arquivo = fopen("Clientes.txt", "rb+");

    cabecalho();

    if(arquivo == NULL){

        printf("Erro ao abrir o arquivo\n");
    }

    int i = 1, id, op;

    printf("CODIGO DO CLIENTE: ");
    scanf("%d", &id);
    getchar();
    id--;
        
        while(fread(&clt, sizeof(CADASTRO), 1, arquivo)){

                i++;

            if(id  >= 0 && id < i - 1){

            printf("\n\nCLIENTE: %s\t", clt.nome);
            printf("CONTATO: %s\n", clt.tel);
            printf("ENDERECO: %s\t", clt.end);
            printf("PONTO DE REF: %s\n", clt.ref);
            printf("BAIRRO: %s\t", clt.bairro);
            printf("CIDADE: %s\n\n", clt.cidade);
            printf("VALOR: R$ %d\n", clt.valor);
            printf("VENCIMENTO: %.2d/%.2d/%d\n", clt.venci.dia, clt.venci.mes, clt.venci.ano);
            printf("---------------------------------------------------------\n\n");

            printf("\t\t\t\t\t[SELECIONE A OPCAO DESEJADA]\n\n");
            printf("[1] NOME | [2] CONTATO | [3] END. | [4] REF. | [5] BAIRRO | [6] CIDADE | [7] VALOR | [8] VENCIMENTO\n\n");

            printf("O QUE DESEJA ALTERAR?\n");
            scanf("%d", &op);
            fflush(stdin);

            if(op > 8 || op <= 0){

                printf("\n[OPCAO INVALIDA]\n");
                break;
            }

            if(op == 1){

                printf("\nDIGITE O NOVO NOME: ");
                gets(clt.nome);
                
                fseek(arquivo, id * sizeof(CADASTRO), SEEK_SET);
                fwrite(&clt, sizeof(CADASTRO), 1, arquivo);

                fclose(arquivo);

                printf("\nNOME ALTERADO COM SUCESSO!\n");
                break;

            }

            if(op == 2){

                printf("\nDIGITE O NOVO NUMERO: ");
                gets(clt.tel);

                fseek(arquivo, id * sizeof(CADASTRO), SEEK_SET);
                fwrite(&clt, sizeof(CADASTRO), 1, arquivo);

                fclose(arquivo);

                printf("\nCONTATO ALTERADO COM SUCESSO!\n");
                break;

            }

            if(op == 3){

                printf("\nDIGITE O NOVO ENDERECO: ");
                gets(clt.end);

                fseek(arquivo, id * sizeof(CADASTRO), SEEK_SET);
                fwrite(&clt, sizeof(CADASTRO), 1, arquivo);

                fclose(arquivo);

                printf("\nENDERECO ALTERADO COM SUCESSO!\n");
                break;

            }

            if(op == 4){

                printf("\nDIGITE O NOVO PONTO DE REF: ");
                gets(clt.ref);

                fseek(arquivo, id * sizeof(CADASTRO), SEEK_SET);
                fwrite(&clt, sizeof(CADASTRO), 1, arquivo);

                fclose(arquivo);

                printf("\nPONTO DE REFERENCIA ALTERADO COM SUCESSO!\n");
                break;

            }

            if(op == 5){

                printf("\nDIGITE O NOVO BAIRRO: ");
                gets(clt.bairro);

                fseek(arquivo, id * sizeof(CADASTRO), SEEK_SET);
                fwrite(&clt, sizeof(CADASTRO), 1, arquivo);

                fclose(arquivo);

                printf("\nBAIRRO ALTERADO COM SUCESSO!\n");
                break;

            }

            if(op == 6){

                printf("\nDIGITE A NOVA CIDADE: ");
                gets(clt.cidade);

                fseek(arquivo, id * sizeof(CADASTRO), SEEK_SET);
                fwrite(&clt, sizeof(CADASTRO), 1, arquivo);

                fclose(arquivo);

                printf("\nCIDADE ALTERADA COM SUCESSO!\n");
                break;

            }

            if(op == 7){

                printf("\nVALOR: ");
                scanf("%d", &clt.valor);

                fseek(arquivo, id * sizeof(CADASTRO), SEEK_SET);
                fwrite(&clt, sizeof(CADASTRO), 1, arquivo);

                fclose(arquivo);

                printf("\nVALOR ALTERADO COM SUCESSO!\n");
                break;

            }

            if(op == 8){

                printf("\nDIGITE O NOVO VENCIMENTO: ");
                scanf("%d %d %d", &clt.venci.dia, &clt.venci.mes, &clt.venci.ano);

                fseek(arquivo, id * sizeof(CADASTRO), SEEK_SET);
                fwrite(&clt, sizeof(CADASTRO), 1, arquivo);

                fclose(arquivo);

                printf("\nVENCIMENTO ALTERADO COM SUCESSO!\n");
                break;

            }

            }

        }
    }

void financeiro(){

    int opco;
    float valor = 0, novoValor;

    FILE* arquivo;

    cabecalho();

    printf("\t\t\t\t\t[1] ARMAZEM | [2] PAGAMENTOS | [3] CONSULTAS\n");
    printf("\t\t\t\t\t\t            ");scanf("%d", &opco);

        switch(opco){

            case 1:

                arquivo = fopen("C:\\Users\\gusta\\Desktop\\Projetos\\CestasAlencar\\Financeiro\\valor.txt", "r");

                fscanf(arquivo, "%f", &valor);

                printf("NOVA COMPRA: ");
                scanf("%f", &novoValor);

                if(novoValor < 0){

                    printf("\nDIGITE UM VALOR VALIDO\n");
                    break;
                }

                if(arquivo == NULL){

                    printf("\nERRO AO ABRIR ARQUIVO\n");

                } else {

                    FILE* arq;

                    arq = fopen("C:\\Users\\gusta\\Desktop\\Projetos\\CestasAlencar\\Financeiro\\valor.txt", "w");

                    valor = novoValor + valor;

                    fprintf(arquivo, "%.2f", valor);
                    fprintf(arq, "%.2f", valor);
                    printf("\nVALOR ADICIONADO COM SUCESSO\n");

                fclose(arquivo);
                fclose(arq);
                break;
                }

            case 2: ;

            cabecalho();

            float pagamento;

                    printf("\t\t\t\t            INFORME O PAGAMENTO: ");
                    scanf("%f", &pagamento);

                    if(pagamento <= 0){

                        printf("\nDIGITE UM VALOR VALIDO\n");
                        break;

                    }

                    struct {

                        int tm_mday;
                        int tm_mon;
                        int tm_year;
                        
                    };

                    struct tm *data_hora_atual;
                    time_t segundos;

                    time(&segundos);
                    data_hora_atual = localtime(&segundos);

                    arquivo = fopen("C:\\Users\\gusta\\Desktop\\Projetos\\CestasAlencar\\Financeiro\\Compras.txt", "r+");

                    fscanf(arquivo, "%f", &valor);

                    pagamento = pagamento - valor;

                    arquivo = fopen("C:\\Users\\gusta\\Desktop\\Projetos\\CestasAlencar\\Financeiro\\Compras.txt", "a");

                    fprintf(arquivo, "Data do pagamento %.2d/%.2d/%.4d\n", data_hora_atual->tm_mday, data_hora_atual->tm_mon+1, data_hora_atual->tm_year+1900);
                    fprintf(arquivo, "VALOR: %.2f\n\n", pagamento);

                    printf("\nPAGAMENTO EFETUADO\n");

                    fclose(arquivo);

                    arquivo = fopen("C:\\Users\\gusta\\Desktop\\Projetos\\CestasAlencar\\Financeiro\\valor.txt", "r");

                    fscanf(arquivo, "%f", &valor);

                    valor = valor - pagamento;

                    arquivo = fopen("C:\\Users\\gusta\\Desktop\\Projetos\\CestasAlencar\\Financeiro\\valor.txt", "w");

                    fprintf(arquivo, "%.2f", valor);

                    fclose(arquivo);
                
                break;

                case 3: ;
                    
                    int pag, ign, count = 0;
                    char ler [50] [1000];

                    arquivo = fopen("C:\\Users\\gusta\\Desktop\\Projetos\\CestasAlencar\\Financeiro\\Compras.txt", "r");

                    printf("\t\t\t\t\t\tINFORME OS ULTIMOS: ");
                    scanf("\t\t\t\t\t\t\t\t%d", &pag);

                    while(fgets(ler[count], 50, arquivo) != NULL){
                        
                        count++;
                    }

                    ign = (count/3) - pag;

                    for(int i = ign*3; i < count; i++){

                        printf("%s", ler[i]);
                    }

                    fclose(arquivo);
                    break;
        }
}
