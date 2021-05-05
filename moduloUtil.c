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
    printf("///                            ATENÇÃO !!                             ///\n");
    printf("///                                                                   ///\n");
    printf("///         Informamos que ouve um erro na abertura do arquivo.       ///\n");
    printf("///         A possível causa do erro pode estar relacionada a         ///\n");
    printf("///         ausência de informações no Banco de Dados. Recomen-       ///\n");
    printf("///         damos utilizar algumas das funções de cadastro e so       ///\n");
    printf("///         então retornar a esta função.                             ///\n");
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
        printf("///            - Preço: R$ ");
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

char* retornaDiaConvertido(void){

    time_t timer;
	struct tm *horarioLocal;
	time(&timer); // Obtem informações de data e hora
	horarioLocal = localtime(&timer); // Converte a hora atual para a hora local
	int x = horarioLocal->tm_mday;
	
	int aux;
    char* valor;
    valor = (char*) malloc(3*sizeof(char));
	
	if(x >= 1 && x <= 9){
		valor[0] = '0';
		valor[1] = 49;
		valor[2] = '\0';
		for(int i = 0; i < x; i++){
			aux = atoi(valor);
			if(aux == x){
				break;
			}else{
				valor[1] += 1;
			}
		}

	}else if(x >= 10 && x <= 19){
		valor[0] = '1';
		valor[1] = 48;
		valor[2] = '\0';
		for(int i = 0; i < x; i++){
			aux = atoi(valor);
			if(aux == x){
				break;
			}else{
				valor[1] += 1;
			}
		}
	}else if(x >= 20 && x <= 29){
		valor[0] = '2';
		valor[1] = 48;
		valor[2] = '\0';
		for(int i = 0; i < x; i++){
			aux = atoi(valor);
			if(aux == x){
				break;
			}else{
				valor[1] += 1;
			}
		}
	}else if(x >= 30 && x <= 31){
		valor[0] = '3';
		valor[1] = 48;
		valor[2] = '\0';
		for(int i = 0; i < x; i++){
			aux = atoi(valor);
			if(aux == x){
				break;
			}else{
				valor[1] += 1;
			}
		}
	}

    return valor;
}

char* retornaMesConvertido(void){

    time_t timer;
	struct tm *horarioLocal;
	time(&timer); // Obtem informações de data e hora
	horarioLocal = localtime(&timer); // Converte a hora atual para a hora local
	int x = horarioLocal->tm_mon + 1;
	
	int aux;
    char* valor;
    valor = (char*) malloc(3*sizeof(char));
	
	if(x >= 1 && x <= 9){
		valor[0] = '0';
		valor[1] = 49;
		valor[2] = '\0';
		for(int i = 0; i < x; i++){
			aux = atoi(valor);
			if(aux == x){
				break;
			}else{
				valor[1] += 1;
			}
		}

	}else if(x >= 10 && x <= 12){
		valor[0] = '1';
		valor[1] = 48;
		valor[2] = '\0';
		for(int i = 0; i < x; i++){
			aux = atoi(valor);
			if(aux == x){
				break;
			}else{
				valor[1] += 1;
			}
		}
	}

    return valor;
}

char* retornaAnoConvertido(void){

    time_t timer;
	struct tm *horarioLocal;
	time(&timer); // Obtem informações de data e hora
	horarioLocal = localtime(&timer); // Converte a hora atual para a hora local
	int x = horarioLocal->tm_year + 1900;
	int aux;
    char* valor;
    valor = (char*) malloc(5*sizeof(char));

	if(x >= 2021 && x <= 2029){
		valor[0] = '2';
		valor[1] = '0';
		valor[2] = '2';
		valor[3] =  49;
		valor[4] = '\0';
		for(int i = 0; i < x; i++){
			aux = atoi(valor);
			if(aux == x){
				break;
			}else{
				valor[3] += 1;
			}
		}

	}else if(x >= 2030 && x <= 2039){
		valor[0] = '2';
		valor[1] = '0';
		valor[2] = '3';
		valor[3] =  48;
		for(int i = 0; i < x; i++){
			aux = atoi(valor);
			if(aux == x){
				break;
			}else{
				valor[3] += 1;
			}
		}
	}

    return valor;
}

char* retornaData(void){

    char* data;
    data = (char*) malloc(11*sizeof(char));

    char* dia = retornaDiaConvertido();
	char* mes = retornaMesConvertido();
	char* ano = retornaAnoConvertido();

    data[0] = ano[0];
	data[1] = ano[1];
	data[2] = ano[2];
	data[3] = ano[3];
	data[4] = '/';
	data[5] = mes[0];
	data[6] = mes[1];
	data[7] = '/';
	data[8] = dia[0];
	data[9] = dia[1];
	data[10] = '\0';

    return data;
}

char* retornaHoraConvertida(void){

    time_t timer;
	struct tm *horarioLocal;

	time(&timer); // Obtem informações de data e hora
	horarioLocal = localtime(&timer); 

	int x = horarioLocal->tm_hour;
	
	int aux;
    char* valor;
    valor = (char*) malloc(3*sizeof(char));
	
	if(x >= 1 && x <= 9){
		valor[0] = '0';
		valor[1] = 49;
		valor[2] = '\0';
		for(int i = 0; i < x; i++){
			aux = atoi(valor);
			if(aux == x){
				break;
			}else{
				valor[1] += 1;
			}
		}

	}else if(x == 0){
		valor[0] = '0';
		valor[1] = '0';
		valor[2] = '\0';
		
	}else if(x >= 10 && x <= 19){
		valor[0] = '1';
		valor[1] = 48;
		valor[2] = '\0';
		for(int i = 0; i < x; i++){
			aux = atoi(valor);
			if(aux == x){
				break;
			}else{
				valor[1] += 1;
			}
		}

	}else if(x >= 20 && x <= 23){
		valor[0] = '2';
		valor[1] = 48;
		valor[2] = '\0';
		for(int i = 0; i < x; i++){
			aux = atoi(valor);
			if(aux == x){
				break;
			}else{
				valor[1] += 1;
			}
		}
	}

    return valor;
}

char* retornaMinConvertidos(void){

    time_t timer;
	struct tm *horarioLocal;
	time(&timer); // Obtem informações de data e hora
	horarioLocal = localtime(&timer); // Converte a hora atual para a hora local
	int x  = horarioLocal->tm_min;
	
    int aux;
    char* valor;
    valor = (char*) malloc(3*sizeof(char));
	if(x == 0){
		valor[0] = '0';
		valor[1] = '0';
		valor[2] = '\0';

	}else if(x >= 1 && x <= 9){
		valor[0] = '0';
		valor[1] = 49;
		valor[2] = '\0';
		for(int i = 0; i < x; i++){
			aux = atoi(valor);
			if(aux == x){
				break;
			}else{
				valor[1] += 1;
			}
		}

	}else if(x >= 10 && x <= 19){
		valor[0] = '1';
		valor[1] = 48;
		valor[2] = '\0';
		for(int i = 0; i < x; i++){
			aux = atoi(valor);
			if(aux == x){
				break;
			}else{
				valor[1] += 1;
			}
		}
	}else if(x >= 20 && x <= 29){
		valor[0] = '2';
		valor[1] = 48;
		valor[2] = '\0';
		for(int i = 0; i < x; i++){
			aux = atoi(valor);
			if(aux == x){
				break;
			}else{
				valor[1] += 1;
			}
		}
	}else if(x >= 30 && x <= 39){
		valor[0] = '3';
		valor[1] = 48;
		valor[2] = '\0';
		for(int i = 0; i < x; i++){
			aux = atoi(valor);
			if(aux == x){
				break;
			}else{
				valor[1] += 1;
			}
		}

	}else if(x >= 40 && x <= 49){
		valor[0] = '4';
		valor[1] = 48;
		valor[2] = '\0';
		for(int i = 0; i < x; i++){
			aux = atoi(valor);
			if(aux == x){
				break;
			}else{
				valor[1] += 1;
			}
		}
	}else if(x >= 50 && x <= 59){
		valor[0] = '5';
		valor[1] = 48;
		valor[2] = '\0';
		for(int i = 0; i < x; i++){
			aux = atoi(valor);
			if(aux == x){
				break;
			}else{
				valor[1] += 1;
			}
		}
	}

    return valor;
}

char* retornaSegConvertidos(void){

    time_t timer;
	struct tm *horarioLocal;
	time(&timer); // Obtem informações de data e hora
	horarioLocal = localtime(&timer); // Converte a hora atual para a hora local
	int x  = horarioLocal->tm_sec;

    int aux;
    char* valor;
    valor = (char*) malloc(3*sizeof(char));

	if(x == 0){
		valor[0] = '0';
		valor[1] = '0';
		valor[2] = '\0';

	}else if(x >= 1 && x <= 9){
		valor[0] = '0';
		valor[1] = 49;
		valor[2] = '\0';
		for(int i = 0; i < x; i++){
			aux = atoi(valor);
			if(aux == x){
				break;
			}else{
				valor[1] += 1;
			}
		}

	}else if(x >= 10 && x <= 19){
		valor[0] = '1';
		valor[1] = 48;
		valor[2] = '\0';
		for(int i = 0; i < x; i++){
			aux = atoi(valor);
			if(aux == x){
				break;
			}else{
				valor[1] += 1;
			}
		}
	}else if(x >= 20 && x <= 29){
		valor[0] = '2';
		valor[1] = 48;
		valor[2] = '\0';
		for(int i = 0; i < x; i++){
			aux = atoi(valor);
			if(aux == x){
				break;
			}else{
				valor[1] += 1;
			}
		}
	}else if(x >= 30 && x <= 39){
		valor[0] = '3';
		valor[1] = 48;
		valor[2] = '\0';
		for(int i = 0; i < x; i++){
			aux = atoi(valor);
			if(aux == x){
				break;
			}else{
				valor[1] += 1;
			}
		}

	}else if(x >= 40 && x <= 49){
		valor[0] = '4';
		valor[1] = 48;
		valor[2] = '\0';
		for(int i = 0; i < x; i++){
			aux = atoi(valor);
			if(aux == x){
				break;
			}else{
				valor[1] += 1;
			}
		}
	}else if(x >= 50 && x <= 59){
		valor[0] = '5';
		valor[1] = 48;
		valor[2] = '\0';
		for(int i = 0; i < x; i++){
			aux = atoi(valor);
			if(aux == x){
				break;
			}else{
				valor[1] += 1;
			}
		}
	}

    return valor;
}

char* retornaHora(void){

    char* hora;
    hora = (char*) malloc(9*sizeof(char));

    char* hour = retornaHoraConvertida();
	char* min = retornaMinConvertidos();
	char* seg = retornaSegConvertidos();	

    hora[0] = hour[0];
	hora[1] = hour[1];
	hora[2] = ':';
	hora[3] = min[0];
	hora[4] = min[1];
	hora[5] = ':';
	hora[6] = seg[0];
	hora[7] = seg[1];
	hora[8] = '\0'; 

    return hora;
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

char* dataReinvertida(char* data){

    char* dataAux;
    dataAux = (char*) malloc(11*sizeof(char));
	dataAux[0] = data[8];
	dataAux[1] = data[9];
	dataAux[2] = '/';
	dataAux[3] = data[5];
	dataAux[4] = data[6];
	dataAux[5] = '/';
	dataAux[6] = data[0];
	dataAux[7] = data[1];
	dataAux[8] = data[2];
	dataAux[9] = data[3];
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
        printf("///            - Mês da compra (mm/aaaa): ");
        scanf("%[^\n]", dataCompra);
        getchar();
    
        validaDig = testeDigitosNumericosData(dataCompra);
        validaNull = verificaNulo(dataCompra);

        if (validaDig || validaNull) {
            printf("///            Data inválida, tente novamente !\n");
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
        printf("///            - Mês do consumo (mm/aaaa): ");
        scanf("%[^\n]", dataConsumo);
        getchar();
    
        validaDig = testeDigitosNumericosData(dataConsumo);
        validaNull = verificaNulo(dataConsumo);

        if (validaDig || validaNull) {
            printf("///            Data inválida, tente novamente !\n");
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
            printf("///            Data inválida, tente novamente !\n");
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
            printf("///            Data inválida, tente novamente !\n");
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






