#include <stdio.h>

int main () {

	char array[20] = { 'H', 'T', 'M', 'A', 'V', 'B', 'C', 'I', 'E', 'R', 'D', 'N', 'L' };
	char aux;

	for(int i = 0; i <= 12; i++) 
		printf("'%c',  ", array[i]);

	printf("\n\n");

	for (int i = 0; i <= 12; i++)
	{
		for (int j = i; j <= 12; j++)
		{
			if (array[j] < array[i]){
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
			}
		}
		printf("'%c',  ", array[i]);
	}
	printf("\nArray Ordenado\n");
	return 0;
}