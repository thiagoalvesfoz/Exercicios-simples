/* 

Thiago Alves | Curso de Engenharia de Software | Faculdade Uniamérica - 2019/2023.

Conversor de numero decimal para binário utilizando a lógica do par ou impar.

Como todos provavelmente devem saber, todo número par é divido por 2, ou seja, caso o
resultado da divisão não tenha restos então o par é verdadeiro "1" caso contrário é falso "0".

Para chegar ao resultado do número binário deve se fazer a divisão do número fornecido pelo 
usuário e verificar se o resto da divisão irá retornar verdadeiro(1) ou falso(0). 
Esse processo será repetido e armazenado em um vetor até que o resultado da ultima divisão 
chegue no valor 1 ou 0 e não dê mais para dividir. Então imprimimos na tela o resultado e voilà.

Em breve alguns updates que faz a conversão de binário para decimal.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

void binario();
void reverse();

#define BITLIMIT 127

int main() {

	printf("\nDigite um numero: ");

	//input stdin
	int n;
	scanf("%d", &n);

	binario(n);

	return 0;
}

void binario(int dec) { 

	char aux[127]; //irá armazenar o número binário
	int bits; //novo recurso - contagem de bits.

	for (int i = 0; i <= BITLIMIT; i++){ //limite de bits estabelecidos.
		
		bits = i + 1; //contador de bits.

		//antes de realizar a divisão verifica se o valor é menor que 2;
		if (dec == 1){ 
			aux[i] = '1'; 
			break; 
		} 
		else if(dec == 0){
			aux[i] = '0'; 
			break;
		}
		//caso contrário, vai calcular o resto da divisão. Se houver resto
		//será armazenamo na posição 'i' do vetor manipulado, o valor binario '1', se
		//não houver, então será armazenado o valor binário '0'.
		else { 
			int resto = dec % 2; 			
			if (resto > 0) 
				aux[i] = '1'; 	  
		  	else 
				aux[i] = '0'; 
		}

		dec /= 2;  //divide novamente por 2 antes de ir para o próximo loop.
	}
	
	// O valor binario está pronto, porém está ao contrario,
	// chamamos a função reverse para corrigir esse problema
	reverse(aux);
	

	//Informação adicional, quantos bits é necessário para armazenar um número decimal?
	printf("\nTamanho: %d bit", bits);	

	if(bits > 1)
		printf("s\n");	// Mero capricho
}

void reverse(char string[127]) {

	char reverse[127] = {'0'}; //espaço para guardar binario + limpando sujeira.
	int p = 0; //indica a posição em que se encontra o numero binario
	
	for (int i = strlen(string); i >= 0; i--) {
		if(string[i] == '0' || string[i] == '1'){ // validação de dados
			reverse[p] = string[i]; //faz a troca;
			p++;
		} 
	}

	printf("\nValor em binario: %s", reverse);

}