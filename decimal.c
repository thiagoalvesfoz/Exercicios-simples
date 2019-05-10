#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void inverter();
int convert_to_decimal();

char aux[127] = {'0'};
int bits = 0;

int main () {

	//input stdin
	int n;
	scanf("%d", &n);


	sprintf(aux, "%d", n);	 	//transforma em string
	inverter(); 				//inverte a string para realizar a conta.	
	n = convert_to_decimal();	//Realiza a conta e retorna o resultado da operação.

	printf("\nValor em decimal: %d", n);
	printf("\nTamanho: %d bit", bits);
	if(bits > 1)
		printf("s\n");	// Mero capricho

	return 0;
	
}

void inverter() {

	char reverse[127] = {'0'};
	int p = 0; //posiçao do n binário
	
	for (int i = strlen(aux); i >= 0; i--) {
		if(aux[i] == '0' || aux[i] == '1'){//validação de dados
			reverse[p] = aux[i];
			p++;
		}
	}

	strcpy(aux, reverse);
}

///função que transformar em decimal
int convert_to_decimal() {

	int decimal = 0;
	int posicao = strlen(aux) - 1; //Essencial para a precisão do resultado.

	for(int i = posicao; i >= 0; i--) {		
		if (aux[i] != '0'){
			//DEBUG printf("\nNa casa %d o resultado sera %c * 2^%d", i, reverse[i], i);
			int resultado = pow(2, i);
			//DEBUG printf("\nO resultado e': %d", resultado);
			decimal += resultado;
		}
	}
	bits = posicao + 1;
	return decimal;
}