/* 

Thiago Alves | Curso de Engenharia de Software | Faculdade Uniamérica - 2019/2023.

Conversor de numero decimal para binário utilizando a lógica do par ou impar.

Como todos provavelmente devem saber, todo número par é divido por 2, ou seja, caso o
resultado da divisão não tenha restos então o par é verdadeiro "1" caso contrário é falso "0".

*** !importante: Para a aplicação desse exercício, os seus valores serão negados(invertidos). ***

Para chegar ao resultado do número binário deve se fazer a divisão do número fornecido pelo stdin e
verificar se o resto da divisão é verdadeiro ou não. Esse processo será repetido e armazenado em um 
vetor até que o resultado da ultima divisão chegue no valor 1 ou 0.

Quando não der mais para dividir, imprimimos o vetor ao contrário e voilà.

Está é a primeira versão do código, em breve alguns updates que faz a conversão de binário para decimal.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

void binario();
void reverse();

int main() {


	//input stdin
	int n;
	scanf("%d", &n);

	binario(n);

	return 0;
}

void binario(int dec) { //metodo impar ou par + resto da divisão;

	char aux[127]; //irá armazenar o número binário
	int bits;

	for (int i = 0; i <= 127; i++){ //limite estabelecido.
		
		bits = i + 1; //novo recurso - contagem de bits.

		if (dec == 1){ //se o número é igual a 1, então...
			aux[i] = '1'; //na posição "i" irá conter o caractere '1';
			break; //quebra o loop evitando processamento desnecessário.
		}
		else if(dec == 0){ //mas se o número é igual a 0, então...
			aux[i] = '0'; //na posição "i" irá conter o caractere '0';
			break;
		}
		else { //Caso contrário, irá fazer o calculo do resto da divisão.
			int resto = dec % 2; 			
			if (resto > 0) //se terminar em impar
				aux[i] = '1'; //na posição "i" irá conter o caractere '1';		  
		  	else //se terminar em par;
				aux[i] = '0'; //na posição "i" irá conter o caractere '0';
		}
		//para continuar a descobrir o próximo valor, deve-se dividir por 2 até que chegue ao valor de 1;
		dec /= 2; 
	}
	
	//código pronto, agora é necessário que imprima ao contrário na tela o resultado;
	//para descobrir o tamanho total do vetor preenchido utilizamos a função strlen;
	
	// printf("\n");
	// for (int j = strlen(aux); j >= 0; j--) {
	// 	printf("%c", aux[j]);				
	// } 

	reverse(aux);
	
	printf("\nTamanho: %d bit", bits);
	
	if(bits > 1)
		printf("s\n");	
}

void reverse(char string[127]) {

	char reverse[127] = {'0'}; //variável auxiliar
	int p = 0; //posiçao do n binário
	
	for (int i = strlen(string); i >= 0; i--) {
		if(string[i] == '0' || string[i] == '1'){//validação de dados
			reverse[p] = string[i];
			p++;
		} 
	}

	printf("\n%s", reverse);

}