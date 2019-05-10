/* 

Thiago Alves | Curso de Engenharia de Software | Faculdade Uniamérica - 2019/2023.

Conversor de numero decimal para binário utilizando a lógica do par ou impar.

Como todos provavelmente devem saber, todo número par é divido por 2, ou seja, caso o
resultado da divisão não tenha restos então o par é verdadeiro "1" caso contrário é falso "0".

Para chegar ao resultado do número binário deve se fazer a divisão do número fornecido pelo 
usuário e verificar se o resto da divisão irá retornar verdadeiro(1) ou falso(0). 
Esse processo será repetido e armazenado em um vetor até que o resultado da ultima divisão 
chegue no valor 1 ou 0 e não dê mais para dividir. Então imprimimos na tela o resultado e voilà.

MELHORIAS
# Menu de opção
# Converte o numero de decimal para binário.
# converte o numero binário para decimal.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int convert_to_binario();
int convert_to_decimal();
void reverse();
void entrada();
void imprima();


char aux[127] = {'0'}; // irá armazenar o número em string
int n = 0; //input stdin
int bits = 0; //contagem de bits.

int main() {

	int opcao;
	printf("\n=== Escolha com Sabedoria ===\n");
	printf("[1]Converter decimal para binario\n");
	printf("[2]Converter binario para decimal\n");
	printf("[?]Sair\n");
	printf("\nDigite: ");
	scanf("%d", &opcao);

	if (opcao == 1) {	
		entrada(opcao);
		convert_to_binario(n);
		imprima(opcao);
	} else if (opcao == 2){
		//resolução numero decimal para binario
		entrada(opcao);
		n = convert_to_decimal();
		imprima(opcao);
	}

	else
		printf("\nSaindo do aplicativo...");

	return 0;
}

int convert_to_binario(int dec) { 

	const int BITLIMIT = 127;  //limite de bits estabelecidos.

	for (int i = 0; i <= BITLIMIT; i++){
		
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
		//será armazenamo na posição 'i' do vetor manipulado o valor binario '1', se
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

	reverse(); //reordena o numero binario
}

int convert_to_decimal() {
	
	reverse(); //inverte a string antes de realizar a operaçao.
	int posicao = strlen(aux) - 1; //Essencial para a precisão do resultado.
	int decimal = 0;

	for(int i = posicao; i >= 0; i--) {
		if (aux[i] != '0'){
			//DEBUG printf("\nNa casa %d o resultado sera %c * 2^%d", i, aux[i], i);
			int resultado = pow(2, i);
			decimal += resultado;
			//DEBUG printf("\nO resultado e': %d", resultado);
		}
	}

	bits = posicao + 1; //calcula o numero de bits ocupado.
	return decimal; //retorna o resultado da operacao
}

void reverse() { //responsável por reordenar a string

	char reverse[127] = {'0'};
	int p = 0; //posiçao do n binário
	
	for (int i = strlen(aux); i >= 0; i--) {
		if(aux[i] == '0' || aux[i] == '1'){ //validação de dados
			reverse[p] = aux[i];
			p++;
		}
	}

	strcpy(aux, reverse);
}

void entrada(int opcao){
	
	//input stdin
	printf("\nDigite um numero: ");
	scanf("%d", &n);

	if (opcao == 2);
		sprintf(aux, "%d", n);

	//DEBUG printf("\ninteiro: %d \n string: %s \n", n, aux);

	//Em breve - validação de dados
	
}

void imprima(int opcao){ //mostra o resultado de acordo com a opção escolhida.
	
	if (opcao == 1) { 
		printf("\nValor em binario: %s", aux);
	} else
		printf("\nValor em decimal: %d", n);

	printf("\nTamanho: %d bit", bits);
	if(bits > 1)
		printf("s\n");	// Mero capricho
}