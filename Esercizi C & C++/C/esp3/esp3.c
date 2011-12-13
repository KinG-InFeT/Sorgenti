#include<stdio.h>
#include<string.h>

char frase[] = "Questo e' un vettore dic aratteri in C .";

char stampa_pari();
char stampa_dispari();

char main() {
	stampa_pari();
	printf("\n");
	stampa_dispari();
	printf("\n\n");
}

char stampa_pari() {
	int i;

	for(i=0; i < strlen(frase); i++)
		if(i%2 == 0)
			printf("%c", frase[i]);
		else
			printf(" ");
}

char stampa_dispari() {
	int i;

	for(i=0; i < strlen(frase); i++)
		if(!(i%2 == 0))
			printf("%c", frase[i]);
		else
			printf(" ");
}
