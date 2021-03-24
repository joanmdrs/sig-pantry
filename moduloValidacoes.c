#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void limpaTela(void){
	system("clear");
}

// A função testeDigito realiza a validação de uma variavel de apenas um dígito.

int testeDigito(char n){
  	int cont = 0;
  
  	if(isdigit(n)){
    	cont++;
	}
  
	if(cont >= 1){
		return 1;

	}else{
		return 0;
	}
}

// A função testeDigitos realiza a validação de uma variavel de um ou mais dígitos, acrescentando 
// 1 ao contador, quando a variável possui um caracter numérico naquela posição.

int testeDigitos(char n[]){
	int cont = 0;
	int i;
	int tam;

	tam = strlen(n);

	for(i=0; i<tam; i++){

		if(isdigit(n[i])){
			cont++;
		}
	}

	if(cont >= 1){
		return 1;

	}else{
		return 0;
	}
}

// A função testeDigitosNumericos realiza a validação de uma variavel de um ou mais digitos, acrescentando
// 1 ao contador quando a variável não possui um caracter numérico naquela posição.

int testeDigitosNumericos(char n[]){
	int cont = 0;
	int i;
	int tam;

	tam = strlen(n);

	for(i=0; i<tam; i++){

		if(!isdigit(n[i])){
			cont++;
		}
	}

	if(cont >= 1){
		return 1;

	}else{
		return 0;
	}
}

// A função testeDigitosNumericosData realiza a validação de uma variavel de um ou mais digitos, acrescentando
// 1 ao contador, quando a variável possui um caracter não numérico e diferente de '/' naquela posição.

int testeDigitosNumericosData(char n[]){
	int cont = 0;
	int i;
	int tam;

	tam = strlen(n);

	for(i=0; i<tam; i++){

		if(!isdigit(n[i]) && n[i] != '/' ){
			cont++;
		}
	}

	if(cont >= 1){	
		return 1;

	}else{
		return 0;
	}
}

// A função testeDigitosNumericosHora realiza a validação de uma variavel de um ou mais digitos, acrescentando
// 1 ao contador, quando a variável possui um caracter não numérico e diferente de ':'

int testeDigitosNumericosHora(char n[]){
	int cont = 0;
	int i;
	int tam;

	tam = strlen(n);

	for(i=0; i<tam; i++){

		if(!isdigit(n[i]) && n[i] != ':' ){
			cont++;
		}
	}

	if(cont >= 1){
		return 1;

	}else{
		return 0;
	}
}

// A função testeDigitosNumericosValorFlutuante realiza a validação de uma variavel de um ou mais digitos, 
// acrescentando 1 ao contador, quando a variável possui um caracter não numérico e diferente de '.'

int testeDigitosNumericosValorFlutuante(char n[]){
	int cont = 0;
	int i;
	int tam;

	tam = strlen(n);

	for(i=0; i<tam; i++){

		if(!isdigit(n[i]) && n[i] != '.' ){
			cont++;
		}
	}

	if(cont >= 1){
		return 1;

	}else{
		return 0;
	}
}

// A função converteCharParaInt realiza a conversão de uma variável char para uma variável do tipo int. 

int converteCharParaInt(char n[]){
	int i = 0;
	i = atoi (n);

	return i;
}

// A função converteCharParaDouble realiza a conversão de uma variável char para uma variável do tipo double. 

double converteCharParaDouble(char n[]){
	double i = 0;
	i = strtod (n, NULL);

	return i;
}

// A função validaOpcao define quais são os valores aceitos quando se realiza uma pergunta de SIM ou NÃO

int validaOpcao(char n){

	if (n == 'S' || n == 's' || n == 'N' || n == 'n'){
		return 1;

	}else{
		return 0;
	}
}

// A função validaOpcaoMenu define quais são as opções de menu aceitas pela variável.

int validaOpcaoMenu(char n, int q){

	if (q == 5){
		if (n == '1' || n == '2' || n == '3' || n == '4' || n == '5' || n == '0'  ){
			return 1;
		}else{
			return 0;
		}

	}else if(q == 4){
		if (n == '1' || n == '2' || n == '3' || n == '4' || n == '0'  ){
			return 1;
		}else{
			return 0;
		}
		
	}else if(q == 3){
		if (n == '1' || n == '2' || n == '3' || n == '0'  ){
			return 1;
		}else{
			return 0;
		}
		
	}else{
		return 0;
	}
	
	
}

// A função validaOpcaoLetrasAD define quais são as opções de escolha aceitas pela variável de A a C.

int validaOpcaoLetrasAC(char n){

	if (n == 'a' || n == 'A' || n == 'b' || n == 'B' || n == 'c' || n == 'C' ){
		return 1;
	}else{
		return 0;
	}
}

// A função validaOpcaoLetrasAD define quais são as opções de escolha aceitas pela variável de A a D.

int validaOpcaoLetrasAD(char n){

	if (n == 'a' || n == 'A' || n == 'b' || n == 'B' || n == 'c' || n == 'C' || n == 'd' || n == 'D' ){
		return 1;
	}else{
		return 0;
	}
}

// A função validaOpcaoLetrasAE define quais são as opções de escolha aceitas pela variável de A a E.

int validaOpcaoLetrasAE(char n){

	if (n == 'a' || n == 'A' || n == 'b' || n == 'B' || n == 'c' || n == 'C' || n == 'd' || n == 'D' || n == 'e' || n == 'E' ){
		return 1;

	}else{
		return 0;
	}
}

// A função validaCodBarras verifica por meio de um cálculo, se o código de barras informado é válido.

int validaCodBarras(char codBarras[]){
 
	float somaPares = 0.0;  // --> variável destinada à receber a soma dos caracteres pares da variável char codBarras[14]
	float somaImpares = 0.0;// --> variável destinada à receber a soma dos caracteres ímpares da variável char codBarras[14]
	float somaTotal = 0.0;  // --> variável destinada à receber a soma dos caracteres pares e ímpares da variável char codBarras[14]
	float resultadoF = 0.0; // --> variável destinada à receber o valor flutuante do valor armazenado na variável (float somaTotal) dividido por 10
	int resultadoI = 0;     // --> variável destinada à receber a parte inteira do valor armazenado na variável (float resultadoF) 
	char aux[2];            // --> variável destinada à auxiliar na conversão do valor char para int.
	float numConv = 0.0;    // --> variável destinada à receber o valor char convertido para int
	int digitoI;            // --> variável destinada à receber o último caractere (dígito verificador) informado pelo usuário da variável char codBarras[14]
	int digitoC;            // --> variável destinada à receber o valor calculado, referente ao dígito verificador do código de barras
	int tamanho = 0;        // --> variável destinada à receber a quantidade de caracteres da variável char codBarras[14]

	tamanho = strlen(codBarras);

	if(tamanho == 13){

		for(int i = 0; i < (tamanho - 1); i ++){

			if (i % 2 == 0){
				aux[0] = codBarras[i];
				numConv = atoi(aux);
				somaPares += numConv ;

			}else{
				aux[0] = codBarras[i];
				numConv = atoi(aux);
				somaImpares += numConv;

			}
		}

		somaTotal = somaPares + (somaImpares * 3);
		resultadoF = somaTotal / 10;
		resultadoI = resultadoF;

		if ((resultadoF - resultadoI) >= 0.5){
			resultadoI += 1;
			aux[0] = codBarras[12];
			digitoI = atoi(aux);
			digitoC = ((resultadoI + 1) * 10) - somaTotal;

			if (digitoI == digitoC){
				return 1;

			}else{
				return 0;

			}

		}else{
			resultadoI = resultadoI;
			aux[0] = codBarras[12];
			digitoI = atoi(aux);
			digitoC = ((resultadoI + 1) * 10) - somaTotal;

			if (digitoI == digitoC){
				return 1;

			}else{
				return 0;

			}
		}

	}else{
		return 0;
		
	}

}

// A função testaBissexto verifica se um determinado ano é bissexto

int testaBissexto(int ano) { 

// "adaptado de @flgorgonio, 2021" 
// "Disponível em: https://replit.com/@flaviusgorgonio/ValidaDataComFuncoesc#main.c"

	if (ano == 0){
		return 0;

	}else if (((ano % 4 == 0) && (ano % 100 != 0)) || ano % 400 == 0 ) {
    	return 1;

  	}else{
    	return 0;

  	}
}

// A função testaData verifica se uma determinada data é válida 

int testaData(int dia, int mes, int ano, char n[]) {

	int diaM; // variável destinada à receber o maior dia do mês

	if (strlen(n) == 10){

		if (dia < 1 || dia > 31 ||mes < 1 || mes > 12 || ano == 0 || ano < 2000){
    		return 0;

		}else{

			if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
				diaM = 31;
				
				if (dia >= 1 && dia <= diaM){
					return 1;
				}else{
					return 0;
				}

			}else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
				diaM = 30;

				if (dia >= 1 && dia <= diaM){
					return 1;

				}else{
					return 0;
				}
			
			}else if(mes == 2){

				if (!testaBissexto(ano)) {
					diaM = 28;

					if (dia >= 1 && dia <= diaM){
						return 1;

					}else{
						return 0;
					}

				}else{
					diaM = 29;
					if (dia >= 1 && dia <= diaM){
						return 1;
						
					}else{
						return 0;
					}
				}
			}else{
				return 0;
			}
		}

	}else{
		return 0;
	}
   	
}

// A função testaHora verifica se uma determinada hora é válida 

int testaHora(int hora, int min, char n[]){

	if (strlen(n) == 5){
		if (hora > 23 || min > 59 ){
			return 0;

		}else if (hora >= 0 && hora <=23){
			if(min >= 0 && min <= 59){
				return 1;
			}else{
				return 0;
			}

		}else{
			return 0;
		}
	}else{
		return 0;
	}
}

// A função verificaNulo verifica se o usuário deixou de inserir algum dado

int verificaNulo(char nome[]) {
  int tam;
  tam = strlen(nome);
  if (tam == 0) {
    return 1;
  }else {
    return 0;
  }
}

