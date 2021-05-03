#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "moduloValidacoes.h"

void exibeTecleEnter(void){
    printf("/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void exibeErroArquivo(void){

    limpaTela();
    printf("/////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                   ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        * * *    SIG-PANTRY - Controle de Despensa    * * *        ///\n");
    printf("///        * * * * * * * * * * * * * * * * * * * * * * * * * *        ///\n");
    printf("///        ***************************************************        ///\n");
    printf("///        ___________________________________________________        ///\n");
    printf("///                                                                   ///\n");
    printf("///                            ATENCAO !!                             ///\n");
    printf("///                                                                   ///\n");
    printf("///         Informamos que ouve um erro na abertura do arquivo.       ///\n");
    printf("///         A possivel causa do erro pode estar relacionada a         ///\n");
    printf("///         ausencia de informacoes no Banco de Dados. Recomen-       ///\n");
    printf("///         damos utilizar algumas das funcoes de cadastro e so       ///\n");
    printf("///         entao retornar a esta funcao.                             ///\n");
    printf("///                                                                   ///\n");
    exibeTecleEnter();

}

char* preencheCodBarras(void){
    int validaCod;
    int validaDig;
    int validaNull;

    char* codBarras;
    codBarras = (char*) malloc(14*sizeof(char));

    do{
        printf("///            - Codigo de Barras: ");
        scanf("%[^\n]", codBarras);
        getchar();
    
        validaCod = validaCodBarras(codBarras);
        validaDig = testeDigitosNumericos(codBarras);
        validaNull = verificaNulo(codBarras);

        if(!validaCod || validaDig || validaNull){
            printf("///            Codigo invalido, tente novamente !\n");
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
            printf("///            Data invalida, tente novamente !\n");
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
        printf("///            - Descricao do Item: ");
        scanf("%[^\n]", nomeItem);
        getchar();

        validaDig = testeDigitos(nomeItem);
        validaNull = verificaNulo(nomeItem);

        if(validaDig || validaNull){
            printf("///            Caracteres invalidos, tente novamente !\n");
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
            printf("///            Caracteres invalidos, tente novamente !\n");
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
            printf("///            Digitos invalidos, tente novamente !\n");
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
        printf("///            - Confirmar a exclusao (S/N) ? ");
        scanf("%[^\n]", &resposta);
        getchar();

        validaDig = testeDigito(resposta);
        validaOp = validaOpcao(resposta);
        
        if(!validaOp || validaDig){
            printf("///            Opcão invalida, tente novamente!\n");
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

int pegaDia(void){

	time_t timer;
	struct tm *horarioLocal;
	time(&timer); // Obtem informações de data e hora
	horarioLocal = localtime(&timer); // Converte a hora atual para a hora local
	int dia = horarioLocal->tm_mday;
	return dia;
}

int pegaMes(void){

	time_t timer;
	struct tm *horarioLocal;
	time(&timer); // Obtem informações de data e hora
	horarioLocal = localtime(&timer); // Converte a hora atual para a hora local
	int mes = horarioLocal->tm_mon + 1;
	return mes;
}

int pegaAno(void){
	time_t timer;
	struct tm *horarioLocal;
	time(&timer); // Obtem informações de data e hora
	horarioLocal = localtime(&timer); // Converte a hora atual para a hora local
	int ano = horarioLocal->tm_year + 1900;
	return ano;
}

// Quando esta função retorna 1 o produto está vencido
int itensVencidos(char n[]){

	char dia[3];
	int day;
	dia[0] = n[0];
	dia[1] = n[1];
	dia[2] = '\0';
	day = atoi(dia);

	char mes[3];
	int month;
	mes[0] = n[3];
	mes[1] = n[4];
	mes[2] = '\0';
	month = atoi(mes);

	char ano[5];
	int year;
	ano[0] = n[6];
	ano[1] = n[7];
	ano[2] = n[8];
	ano[3] = n[9];
	ano[4] = '\0';
	year = atoi(ano);

	int dd, mm, aa;

	dd = pegaDia();
	mm = pegaMes();
	aa = pegaAno();

	if (year > aa){
		return 0;

	}else if(year == aa){

		if(month < mm){
			return 1;

		}else if(month > mm){
			return 0;

		}else if(month == mm){

			if(day <= dd){
				return 1;

			}else if(day > dd){
				return 0;
			}
			
		}

	}else if(year < aa){
		return 1;

	}
	return 0;

}

int itensParaVencer(char n[]){

	char dia[3];
	int day;
	dia[0] = n[0];
	dia[1] = n[1];
	dia[2] = '\0';
	day = atoi(dia);

	char mes[3];
	int month;
	mes[0] = n[3];
	mes[1] = n[4];
	mes[2] = '\0';
	month = atoi(mes);

	char ano[5];
	int year;
	ano[0] = n[6];
	ano[1] = n[7];
	ano[2] = n[8];
	ano[3] = n[9];
	ano[4] = '\0';
	year = atoi(ano);

	int dd, mm, aa;

	dd = pegaDia();
	mm = pegaMes();
	aa = pegaAno();

	if(year < aa){
		return 0;

	}else if(year == aa){

		if(month == mm){

			if(day > dd){
				return 1;
                
			}else{
				return 0;
			}

		}else if(month < mm){
			return 0;

		}else if(month > mm){
			return 1;
		}

	}else if(year > aa){
		return 1;
	}
	return 0;
}

char* dataInvertida(char* data){

    char* dataAux;
    dataAux = (char*) malloc(11*sizeof(char));
	dataAux[0] = data[6];
	dataAux[1] = data[7];
	dataAux[2] = data[8];
	dataAux[3] = data[9];
	dataAux[4] = '/';
	dataAux[5] = data[3];
	dataAux[6] = data[4];
	dataAux[7] = '/';
	dataAux[8] = data[0];
	dataAux[9] = data[1];
	dataAux[10] = '\0';
    return dataAux;
}

char* mesInvertido(char* data){
    char* dataAux;
    dataAux = (char*) malloc(8*sizeof(char));
	dataAux[0] = data[3];
	dataAux[1] = data[4];
	dataAux[2] = data[5];
	dataAux[3] = data[6];
	dataAux[4] = '/';
	dataAux[5] = data[0];
	dataAux[6] = data[1];
	dataAux[7] = '\0';
    return dataAux;
}

char* preencheMesEAno(void){
    int validaDig;
    int validaNull;

    char* dataCompra;
    dataCompra = (char*) malloc(8*sizeof(char));

    do{
        printf("///            - Mes da compra (mm/aaaa): ");
        scanf("%[^\n]", dataCompra);
        getchar();
    
        validaDig = testeDigitosNumericosData(dataCompra);
        validaNull = verificaNulo(dataCompra);

        if (validaDig || validaNull) {
            printf("///            Data invalida, tente novamente !\n");
        }

    }while(validaDig || validaNull);

    char* dataAux;
    dataAux = mesInvertido(dataCompra);
    free(dataCompra);
    return dataAux;

}

char* preencheMesEAnoC(void){
    int validaDig;
    int validaNull;

    char* dataConsumo;
    dataConsumo = (char*) malloc(8*sizeof(char));

    do{
        printf("///            - Mes do consumo (mm/aaaa): ");
        scanf("%[^\n]", dataConsumo);
        getchar();
    
        validaDig = testeDigitosNumericosData(dataConsumo);
        validaNull = verificaNulo(dataConsumo);

        if (validaDig || validaNull) {
            printf("///            Data invalida, tente novamente !\n");
        }

    }while(validaDig || validaNull);

    char* dataAux;
    dataAux = mesInvertido(dataConsumo);
    free(dataConsumo);
    return dataAux;

}

char* recortaMesEAno(char* data){
    char* dataAux;
    dataAux = (char*) malloc(8*sizeof(char));
	dataAux[0] = data[0];
	dataAux[1] = data[1];
	dataAux[2] = data[2];
	dataAux[3] = data[3];
	dataAux[4] = '/';
	dataAux[5] = data[5];
	dataAux[6] = data[6];
	dataAux[7] = '\0';
    return dataAux;
    
}

char* preencheAno(void){
    int validaDig;
    int validaNull;

    char* dataCompra;
    dataCompra = (char*) malloc(5*sizeof(char));

    do{
        printf("///            - Ano da compra (aaaa): ");
        scanf("%[^\n]", dataCompra);
        getchar();
    
        validaDig = testeDigitosNumericosData(dataCompra);
        validaNull = verificaNulo(dataCompra);

        if (validaDig || validaNull) {
            printf("///            Data invalida, tente novamente !\n");
        }

    }while(validaDig || validaNull);

    return dataCompra;
}

char* preencheAnoC(void){
    int validaDig;
    int validaNull;

    char* dataConsumo;
    dataConsumo = (char*) malloc(5*sizeof(char));

    do{
        printf("///            - Ano do consumo (aaaa): ");
        scanf("%[^\n]", dataConsumo);
        getchar();
    
        validaDig = testeDigitosNumericosData(dataConsumo);
        validaNull = verificaNulo(dataConsumo);

        if (validaDig || validaNull) {
            printf("///            Data invalida, tente novamente !\n");
        }

    }while(validaDig || validaNull);

    return dataConsumo;
}

char* recortaAno(char* data){
    char* dataAux;
    dataAux = (char*) malloc(5*sizeof(char));
	dataAux[0] = data[0];
	dataAux[1] = data[1];
	dataAux[2] = data[2];
	dataAux[3] = data[3];
    dataAux[4] = '\0';
    return dataAux;
}






