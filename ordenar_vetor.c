#include <stdio.h>

int main () {

	char array[20] = { 'A', 'T', 'M', 'H', 'V', 'B', 'C', 'I', 'E', 'R', 'D', 'N', 'L' };
	char aux;    	//  0    1    2    H    4    5    6    7    8    9    10  11    12

	for(int i = 0; i <= 12; i++) 
		printf("'%c',  ", array[i]);

	printf("\n\n");

	for (int anterior = 0; anterior <= 12; anterior++)
	{
		for (int proxima = anterior; proxima <= 12; proxima++)
		{
			if (array[proxima] < array[anterior]){
				aux = array[anterior];
				array[anterior] = array[proxima];
				array[proxima] = aux;
			}
		}
		printf("'%c',  ", array[anterior]);
	}
	printf("\nArray Ordenado\n");
	return 0;
}