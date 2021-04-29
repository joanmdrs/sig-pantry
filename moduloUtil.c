#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloValidacoes.h"

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

char confirmaExclusao(void){
    int validaDig;
    int validaOp;
    char resposta;

    do{
        printf("///            - Confirmar a exclusão (S/N) ? ");
        scanf("%[^\n]", &resposta);
        getchar();

        validaDig = testeDigito(resposta);
        validaOp = validaOpcao(resposta);
        
        if(!validaOp || validaDig){
            printf("///            Opcão inválida, tente novamente!\n");
        }
    }while(!validaOp || validaDig);

    return resposta;
}

char confirmaAlteracao(void){
    int validaDig;
    int validaOp;
    char confirma;

    do{
        printf("///            - Confirmar à alteração deste produto (S/N) ? ");
        scanf("%[^\n]", &confirma);
        getchar();

        validaDig = testeDigito(confirma);
        validaOp = validaOpcao(confirma);

        if(!validaOp || validaDig){
            printf("///            Opcão inválida, tente novamente!\n");
        }
    }while(!validaOp || validaDig);

    return confirma;

}