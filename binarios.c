#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binario();

int main() {

  int n;

  scanf("%d", &n);

  binario(n);

  return 0;
}

void binario(int n) { //metodo impar ou par + resto da divisão;

	char aux[127]; //irá armazenar o código binário
	for (int i = 0; i < 127; i++){ //limite suportado de 128 (ou 127) bits
		if (n == 1){ //se o número é igual a 1, então...
			aux[i] = '1';	//na posição "i" irá conter o caractere '1';
			break;
		}
		else { //Caso contrário, irá fazer o calculo do resto da divisão.
			int resto = n % 2; 
			if (resto > 0) //se terminar em impar
			aux[i] = '1'; //na posição "i" irá conter o caractere '1';		  
		  	else //se terminar em par;
			aux[i] = '0'; //na posição "i" irá conter o caractere '0';
		}
		//para continuar a descobrir o próximo valor, deve-se dividir por 2 até que chegue ao valor de 1;
		n /= 2; 
	}

	//código pronto, agora é necessário que imprima ao contrário na tela o resultado;
	//mas antes, é temos que descobrir o tamanho total do vetor preenchido; 
	for (int j = strlen(aux); j >= 0; j--) { //para isso utiliza-se a função strlen
		printf("%c", aux[j]);
	}
}