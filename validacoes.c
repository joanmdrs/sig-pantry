#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int validaOpcao(char n){

	if (n == 'S' || n == 's' || n == 'N' || n == 'n'){
		return 1;
	}else{
		return 0;
	}
}

int validaOpcaoMenu(char n){

	if (n == '1' || n == '2' || n == '3' || n == '4' || n == '0'  ){
		return 1;
	}else{
		return 0;
	}
}

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

int bissexto(int aa) {
  	if ((aa % 4 == 0) && (aa % 100 != 0)) {
    	return 1;
  	}else if (aa % 400 == 0) {
    	return 1;
  	}else{
    	return 0;
  	}
}

int testaData(int dd, int mm, int aa) {
  	int maiorDia;
  	if (aa < 0 || mm < 1 || mm > 12){
    	return 0;
	}
	
  	if (mm == 2) {
    	if (bissexto(aa)) {
      		maiorDia = 29;
		}else{
      		maiorDia = 28;
		}

  	}else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
    	maiorDia = 30;
  	} else{
    	maiorDia = 31;

	}

  	if (dd < 1 || dd > maiorDia){
    	return 0;
	}

  	return 1;
}

int validaHora(int hh, int mm){

	if (hh >= 0 && hh <=23){
		if(mm >= 0 && mm <= 59){
			return 1;
		}else{
			return 0;
		}
	}else{
		return 0;
	}
}