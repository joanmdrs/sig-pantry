#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "moduloValidacoes.h"
#include "moduloCompras.h"

long int preencheCodCompra(void){

    FILE* fc;
    fc = fopen("compras.dat", "rb");

    Compra* com;
    com = (Compra*) malloc(sizeof(Compra));

    long int codCompra;

    codCompra = geraNF();

    while(fread(com, sizeof(Compra), 1, fc)) {
        if ((com->codCompra == codCompra)) {
            codCompra = geraNF();
        }
    }
    fclose(fc);
    free(com);

    return codCompra;
}

char* preencheDataCompra(void){
    
    int validaData;
    int validaDig;
    int validaNull;

    char* dataCompra;
    dataCompra = (char*) malloc(11*sizeof(char));

    do{
        printf("///            - Data Compra (dd/mm/aaaa): ");
        scanf("%[^\n]", dataCompra);
        getchar();
    
        validaData = testaData(dataCompra);
        validaDig = testeDigitosNumericosData(dataCompra);
        validaNull = verificaNulo(dataCompra);

        if (!validaData || validaDig || validaNull) {
            printf("///            Data inválida, tente novamente !\n");
        }

    }while(!validaData || validaDig || validaNull);

    return dataCompra;
}

char* preencheHoraCompra(void){

    int validaHora;
    int validaDig;
    int validaNull;

    char* horaCompra;
    horaCompra = (char*) malloc(9*sizeof(char));

    do{
        printf("///            - Horário Compra (hh:mm:ss): ");
        scanf("%[^\n]", horaCompra);
        getchar();
    
        validaHora = testaHora(horaCompra);
        validaDig = testeDigitosNumericosHora(horaCompra);
        validaNull = verificaNulo(horaCompra);

        if (!validaHora || validaDig || validaNull) {
            printf("///            Hora inválida, tente novamente !\n");
        }

    }while(!validaHora || validaDig || validaNull);

    return horaCompra;
}

char* preencheQuantCompra(void){
    int validaDig;
    int validaNull;
    
    char* quantC;
    quantC = (char*) malloc(20*sizeof(char));

    do{
        printf("///            - Quant. Itens da compra: ");
        scanf("%[^\n]", quantC);
        getchar();
    
        validaDig = testeDigitosNumericos(quantC);
        validaNull = verificaNulo(quantC);  

        if(validaDig || validaNull){
            printf("///            Quantidade inválida, tente novamente !\n");
        }

    }while(validaDig || validaNull);

    return quantC;
}

char* preencheCodBarras(void){
    int validaCod;
    int validaDig;
    int validaNull;

    char* codBarras;
    codBarras = (char*) malloc(14*sizeof(char));

    do{
        printf("///            - Código de Barras: ");
        scanf("%[^\n]", codBarras);
        getchar();
    
        validaCod = validaCodBarras(codBarras);
        validaDig = testeDigitosNumericos(codBarras);
        validaNull = verificaNulo(codBarras);

        if(!validaCod || validaDig || validaNull){
            printf("///            Código inválido, tente novamente !\n");
        }

    }while(!validaCod || validaDig || validaNull);

    return codBarras;
}

char* preencheDataValidade(void){

    int validaData;
    int validaDig;
    int validaNull;

    char* dataValidade;
    dataValidade = (char*) malloc(11*sizeof(char));

    do{
        printf("///            - Data Val. (dd/mm/aaaa): ");
        scanf("%[^\n]", dataValidade);
        getchar();

        validaData = testaData(dataValidade);
        validaDig = testeDigitosNumericosData(dataValidade);
        validaNull = verificaNulo(dataValidade);

        if (!validaData || validaDig || validaNull) {
            printf("///            Data inválida, tente novamente !\n");
        }

    }while(!validaData || validaDig || validaNull);

    return dataValidade;
}

char* preencheDesc(void){

    int validaDig;
    int validaNull;

    char* nomeItem;
    nomeItem = (char*) malloc(51*sizeof(char));

    do{
        printf("///            - Descrição do Item: ");
        scanf("%[^\n]", nomeItem);
        getchar();

        validaDig = testeDigitos(nomeItem);
        validaNull = verificaNulo(nomeItem);

        if(validaDig || validaNull){
            printf("///            Caracteres inválidos, tente novamente !\n");
        }

    }while (validaDig || validaNull);

    return nomeItem;
}

char* preencheLocal(void){

    int validaDig;
    int validaNull;

    char* local;
    local = (char*) malloc(20*sizeof(char));

    do{
        printf("///            - Local: ");
        scanf("%[^\n]", local);
        getchar();

        validaDig = testeDigitos(local);
        validaNull = verificaNulo(local);

        if(validaDig || validaNull){
            printf("///            Caracteres inválidos, tente novamente !\n");
        }

    }while (validaDig || validaNull);

    return local;
}

char* preencheQuantPro(void){

    int validaDig;
    int validaNull;

    char* quantC;
    quantC = (char*) malloc(10*sizeof(char));

    do{
        printf("///            - Quantidade: ");
        scanf("%[^\n]", quantC);
        getchar();
        
        validaDig = testeDigitosNumericos(quantC);
        validaNull = verificaNulo(quantC);

        if(validaDig || validaNull){
            printf("///            Dígitos inválidos, tente novamente !\n");
        }

    }while (validaDig || validaNull);

    return quantC;
}

double preenchePrecoItem(void){

    int validaDig;
    int validaNull;

    double precoD = 0.0;
    char* precoC;
    precoC = (char*) malloc(10*sizeof(char));

    do{
        printf("///            - Preço do Item: R$ ");
        scanf("%s", precoC);
        getchar();
        
        validaDig = testeDigitosNumericosValorFlutuante(precoC);
        validaNull = verificaNulo(precoC);

        if(validaDig){
            printf("///            Dígitos inválidos, tente novamente !\n");
        }

    }while (validaDig || validaNull);

    precoD = converteCharParaDouble(precoC);
    free(precoC);
    return precoD;
}