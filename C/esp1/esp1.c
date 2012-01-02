#include <stdio.h>

int main(void) {
	int numero;
	int conta;
	float somma;
	float media;

	conta = 0;
	somma = 0;
	
	printf("Inserire una serie di numeri.\n\n\n") ;
	printf("Inserisci numero (Digitare 0 per calcolare la media):\n") ;
  	scanf ("%d", &numero) ;

  	while ( numero != 0 ) {
		somma = somma + numero;
		conta = conta + 1 ;
		printf("Inserisci numero (Digitare 0 per camcolare la media):\n") ;
		scanf ("%d", &numero);
	}

	media = somma/conta ;

	printf("\nNumeri inseriti %d, Media %f \n", conta, media);
	
	return 0;
}
