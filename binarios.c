/* 

Thiago Alves | Curso de Engenharia de Software | Faculdade Uniamérica - 2019/2023.

Conversor de numero decimal para binário utilizando a lógica do par ou impar.

Como todos provavelmente devem saber, todo número par é divido por 2, ou seja, caso o
resultado da divisão não tenha restos então o par é verdadeiro "1" caso contrário é falso "0".

*** !importante: Para a aplicação desse exercício, os seus valores serão negados(invertidos). ***

Para chegar ao resultado do número binário deve se fazer a divisão do número fornecido pelo stdin e
verificar se é par ou impar utilizando como referência o resto da divisão. Esse processo será 
repetido e armazenado em um vetor até que o resultado da ultima divisão chegue no valor 1 ou 0.

Quando não der mais para dividir, é só imprimir o vetor de trás para frente e voilà.

Está é a primeira versão do código, em breve algos updates que faz o conversão de binário para decimal.
*/

#include <stdio.h>
#include <string.h>

void binario();

int main() {

  int n;
  scanf("%d", &n);
  binario(n);

  return 0;
}

void binario(int n) { //metodo impar ou par + resto da divisão;

	char aux[127]; //irá armazenar o número binário
	int bits;

	for (int i = 0; i <= 127; i++){ //limite estabelecido.
		
		bits = i+1; //novo recurso - contagem de bits.

		if (n == 1){ //se o número é igual a 1, então...
			aux[i] = '1'; //na posição "i" irá conter o caractere '1';
			break; //quebra o loop evitando processamento desnecessário.
		}
		else if(n == 0){ //mas se o número é igual a 0, então...
			aux[i] = '0'; //na posição "i" irá conter o caractere '0';
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
	//para descobrir o tamanho total do vetor preenchido utilizamos a função strlen;
	
	printf("\n");
	for (int j = strlen(aux); j >= 0; j--) {
		printf("%c", aux[j]);				
	} 
	
	printf("\nTamanho: %d bit", bits);
	
	if(bits > 1)
		printf("s\n");

	
}